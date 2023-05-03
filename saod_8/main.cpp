// STComplete.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>  //Нужно для работы с файлами.
#include <list>
#include "SufTree.h"
#include <chrono>
#include<string>
#include<cstring>

string get_rnd_str(int ab_size, int len)
{
    string s(len,0);
    for (int i = 0; i < len; i++)
    {
        int rch = rand() % ab_size + 'a';
        s [i]= char(rch);
    }
    return s;
}


#define FROM_FILE
int main()
{
#ifdef FROM_FILE
    cout << "Enter a file name (empty for 'rfc 1951.txt'): ";

    string fname;
    char fName[128]{0};
    cin.getline(fName, sizeof(fName));
    if (strlen(fName) == 0)
        strcpy_s(fName, sizeof(fName), "rfc 1951.txt");
    cout << fName << endl;

    ifstream ifs(fName, ios_base::in | ios_base::binary);
    char input[128];

    streampos begin, end;
    begin = ifs.tellg();
    ifs.seekg(0, ios::end);
    end = ifs.tellg();
    cout << "size is: " << (end - begin) << " bytes.\n";
    ifs.seekg(0, ios::beg);

    char* inp = new char[end - begin];
    SufTree st(inp);
    auto start = chrono::steady_clock::now();

    int maxRemaind = 0, iMax = 0;
    char c = ifs.get();
    for (int i = 0; ifs.good(); i++) {
        inp[i] = c;
        st.extend(i);
        c = ifs.get();
    }
    st.finalize();
    auto stop = chrono::steady_clock::now();

    auto maxLen = st.MaxPalindromeLen();
    cout << "Max palindrome length: " << maxLen << endl;

    list<int> palindromes;
    st.GetPalindromes(palindromes, maxLen);
    cout << "Palindromes of length " << maxLen << ": ";
    for (auto& p : palindromes) {
        cout << string(input + p, input + p + maxLen) << " ";
    }
    cout << endl;
    ifs.close();

    cout << "Time difference = " << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << "[ms]" << endl;
#else
    string s = get_rnd_str(2, 7);
    cout << s << endl;
    auto start = chrono::steady_clock::now();

    SufTree st(s.c_str());
    for (int i = 0; i < s.length(); i++)
        st.extend(i);
    // и завершаем построение, делая все суффиксы явными!
    st.finalize();

    auto stop = chrono::steady_clock::now();

    st.FillLeaves();    // Можно и без него, но не будут заполнены индексы суффиксов.

    st.ShowTree();
    cout << endl << endl;
    cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << "[mks]" << endl;

#endif

}
