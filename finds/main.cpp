#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <vector>
#include "timer.h"
using namespace std;

size_t naive(const std::string& str, const std::string& sub)
{
    size_t n = str.size(), m = sub.size();
    if (m == 0)
        return 0;
    std::vector<size_t> lsp(m, 0);
    for (size_t i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && sub[i] != sub[j])
            j = lsp[j - 1];
        if (sub[i] == sub[j])
            j++;
        lsp[i] = j;
    }
    for (size_t i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && str[i] != sub[j])
            j = lsp[j - 1];
        if (str[i] == sub[j])
            j++;
        if (j == m)
            return i - m + 1;
    }
    return std::string::npos;
}

size_t kmp(const std::string& str, const std::string& sub)
{
    size_t n = str.size(), m = sub.size();
    if (m == 0)
        return 0;
    std::vector<size_t> lsp(m, 0);
    for (size_t i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && sub[i] != sub[j])
            j = lsp[j - 1];
        if (sub[i] == sub[j])
            j++;
        lsp[i] = j;
    }
    for (size_t i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && str[i] != sub[j])
            j = lsp[j - 1];
        if (str[i] == sub[j])
            j++;
        if (j == m)
            return i - m + 1;
    }
    return std::string::npos;
}

size_t bm(const std::string& str, const std::string& sub)
{
    int b[128];//(128, -1);
    for(int i = 0; i < 128; i++) b[i] = -1;
    for (size_t i = 0; i < sub.size(); i++)
        b[size_t(sub[i])] = i;
    //b[0] = 4;
    //b[1] = 3;
    //b[2] = 2;
    int s = 0;
    int m = sub.length();
    int n = str.length();
    while (s <= (n - m))
    {
        int j = m - 1;
        while (j >= 0 && sub[j] == str[s + j])
            --j;
        if (j < 0) return s;
        else s += max(1, j - b[str[s + j]]);
    }
    return std::string::npos;
}

int main()
{
    using namespace std;
    double sred=0;
    string str, sub = "was born in a small town called Sceptre";
    ifstream fin("engwiki_ascii.txt", ios::binary);
    if (!fin.is_open())
    {
        cout << "not open!" << endl;
        return 0;
    }
    str.append((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

    size_t n = 50;
    std::vector<size_t> times(n), indx(n);

    cout << "\nstd::find\n";
    for (size_t i = 0; i < n; i++)
    {
        Timer<double>::reset();
        auto index = str.find(sub);
        if (index == std::string::npos)
            std::cout << "not found\n";
        else
            indx[i] = index;
        sred+=Timer<double>::elapsed_milliseconds();
        times[i] = Timer<double>::elapsed_milliseconds();
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << indx[i] << '\t' << times[i] << endl;
    }
    std::cout<<std::endl<<"Sred = "<<sred/n<<std::endl;
    sred=0;
    cout << "\nnaive\n";
    for (size_t i = 0; i < n; i++)
    {
        Timer<double>::reset();
        auto index = naive(str, sub);
        if (index == std::string::npos)
            std::cout << "not found\n";
        else
            indx[i] = index;
        sred+=Timer<double>::elapsed_milliseconds();
        times[i] =  Timer<double>::elapsed_milliseconds();

    }
    for (size_t i = 0; i < n; i++)
    {
        cout << indx[i] << '\t' << times[i] << endl;
    }
    std::cout<<std::endl<<"Sred = "<<sred/n<<std::endl;
    sred =0;
    cout << "\nbm\n";
    for (size_t i = 0; i < n; i++)
    {
        Timer<double>::reset();
        auto index = bm(str, sub);
        if (index == std::string::npos)
            std::cout << "not found\n";
        else
            indx[i] = index;
        sred+=Timer<double>::elapsed_milliseconds();
        times[i] = Timer<double>::elapsed_milliseconds();
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << indx[i] << '\t' << times[i] << endl;
    }
    std::cout<<std::endl<<"Sred = "<<sred/n<<std::endl;
    sred =0;
    cout << "\nkmp\n";
    for (size_t i = 0; i < n; i++)
    {
        Timer<double>::reset();
        auto index = kmp(str, sub);
        if (index == std::string::npos)
            std::cout << "not found\n";
        else
            indx[i] = index;
        sred+=Timer<double>::elapsed_milliseconds();
        times[i] =  Timer<double>::elapsed_milliseconds();
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << indx[i] << '\t' << times[i] << endl;
    }
    std::cout<<std::endl<<"Sred = "<<sred/n<<std::endl;
}
