#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

struct SymbolInfo {
    char symbol;
    int frequency;
    std::vector<bool> code;

    SymbolInfo(char s, int f) : symbol(s), frequency(f) {}
};

std::unordered_map<char, int> countSymbolFrequency(const std::string& filename) {
    std::unordered_map<char, int> frequencyMap;
    std::ifstream file(filename, std::ios::binary);
    char c;

    while (file.get(c)) {
        frequencyMap[c]++;
    }

    file.close();
    return frequencyMap;
}

bool compareSymbolFrequency(const SymbolInfo& a, const SymbolInfo& b) {
    return a.frequency < b.frequency;
}

std::vector<bool> generateFibonacciCode(int number) {
    std::vector<bool> code;
    int fib1 = 1;
    int fib2 = 2;

    while (number >= fib2) {
        int temp = fib1;
        fib1 = fib2;
        fib2 += temp;
    }

    while (fib1 > 0) {
        if (number >= fib1) {
            code.push_back(1);
            number -= fib1;
        } else {
            code.push_back(0);
        }
        int temp = fib1;
        fib1 = fib2 - fib1;
        fib2 = temp;
    }

    std::reverse(code.begin(), code.end());
    code.push_back(1); // append stop bit
    return code;
}

void writeMetadata(const std::string& filename, const std::unordered_map<char, std::vector<bool>>& codes) {
    std::ofstream file(filename, std::ios::binary);
    unsigned int size = codes.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(unsigned int));

    for (const auto& entry : codes) {
        file.write(&entry.first, sizeof(char));
        unsigned int codeSize = entry.second.size();
        file.write(reinterpret_cast<const char*>(&codeSize), sizeof(unsigned int));
        for (unsigned int i = 0; i < codeSize; ++i) {
            unsigned char bit = entry.second[i];
            file.write(reinterpret_cast<const char*>(&bit), sizeof(unsigned char));
        }
    }

    file.close();
}

std::unordered_map<char, std::vector<bool>> readMetadata(const std::string& filename) {
    std::unordered_map<char, std::vector<bool>> codes;
    std::ifstream file(filename, std::ios::binary);

    if (!file) {
        std::cout << "Failed to open metadata file!" << std::endl;
        return codes;
    }

    unsigned int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(unsigned int));

    for (unsigned int i = 0; i < size; ++i) {
        char symbol;
        file.read(&symbol, sizeof(char));
        unsigned int codeSize;
        file.read(reinterpret_cast<char*>(&codeSize), sizeof(unsigned int));

        std::vector<bool> code(codeSize);
        for (unsigned int j = 0; j < codeSize; ++j) {
            unsigned char bit;
            file.read(reinterpret_cast<char*>(&bit), sizeof(unsigned char));
            code[j] = bit;
        }

        codes[symbol] = code;
    }

    file.close();
    return codes;
}

void compressFile(const std::string& inputFile, const std::string& outputFile) {
    std::unordered_map<char, int> frequencyMap = countSymbolFrequency(inputFile);

    // Создаем вектор пар символ-частота
    std::vector<std::pair<char, int>> symbols(frequencyMap.begin(), frequencyMap.end());

    // Сортируем вектор по частоте символов, наиболее часто встречающиеся символы идут первыми
    std::sort(symbols.begin(), symbols.end(),
              [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
                  return a.second > b.second;
              });

    // Создаем карту кодов Фибоначчи
    std::unordered_map<char, std::vector<bool>> codes;
    for (int i = 0; i < symbols.size(); ++i) {
        codes[symbols[i].first] = generateFibonacciCode(i+1);
    }

    writeMetadata(outputFile + ".meta", codes);

    std::ifstream inputFileStream(inputFile, std::ios::binary);
    std::ofstream outputFileStream(outputFile, std::ios::binary);
    char c;
    std::vector<bool> buffer;

    while (inputFileStream.get(c)) {
        const auto code = codes[c];
        buffer.insert(buffer.end(), code.begin(), code.end());

        while (buffer.size() >= 8) {
            char byte = 0;
            for (int i = 0; i < 8; ++i) {
                byte |= (buffer[i] << (7 - i));
            }

            outputFileStream.write(&byte, sizeof(char));
            buffer.erase(buffer.begin(), buffer.begin() + 8);
        }
    }

    if (!buffer.empty()) {
        char lastByte = 0;
        int remainingBits = buffer.size();
        for (int i = 0; i < remainingBits; ++i) {
            lastByte |= (buffer[i] << (7 - i));
        }

        outputFileStream.write(&lastByte, sizeof(char));
    }

    inputFileStream.close();
    outputFileStream.close();
}


char extractSymbol(const std::vector<bool>& buffer, int& index) {
    char symbol = 0;
    for (int i = 0; i < 8; ++i) {
        symbol |= (buffer[index++] << (7 - i));
    }
    return symbol;
}

void decompressFile(const std::string& inputFile, const std::string& outputFile) {
    std::unordered_map<char, std::vector<bool>> codes = readMetadata(inputFile + ".meta");
    std::ifstream inputFileStream(inputFile, std::ios::binary);
    std::ofstream outputFileStream(outputFile, std::ios::binary);

    char c;
    std::vector<bool> buffer;

    while (inputFileStream.get(c)) {
        for (int i = 7; i >= 0; --i) {
            buffer.push_back((c >> i) & 1);

            for (const auto& entry : codes) {
                if (buffer == entry.second) {
                    outputFileStream.write(&entry.first, sizeof(char));
                    buffer.clear();
                    break;
                }
            }
        }
    }

    inputFileStream.close();
    outputFileStream.close();
}

int main() {
    std::string inputFile = "input.txt";
    std::string compressedFile = "compressed.bin";
    std::string decompressedFile = "decompressed.txt";

    compressFile(inputFile, compressedFile);
    decompressFile(compressedFile, decompressedFile);

   // коэф сжатия я посчитал это input.txt/ (compressed.bin+compressed.bin.meta)= 57988 / ( 1279 + 46098 ) = 1,223969436646474

    return 0;
}
