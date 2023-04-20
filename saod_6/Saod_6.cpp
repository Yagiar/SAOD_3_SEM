#include <iostream>
#include "PF.h";

using namespace std;

int main()
{
    setlocale(0, "Russian");
    cout << "2 вариант" << endl << endl;

    PF pf;
    pf.Init("rakaratrakarakarakatakarakara");
    cout << "Длина: " << pf << endl;
    for (int i = 0; i < pf; ++i)
    {
        cout << pf[i];
    }
    cout << endl << endl;

    const int N = 100;
    char s2[N]{ 0 };
    char s3[N / 2]{ 0 };
    char s4[N / 5]{ 0 };
    char s5[N / 10]{ 0 };
    for (int i = 0; i < N - 1; i++)
    {
        s2[i] = rand() % ('c' - 'a') + 'a';
        if (i < N / 2 - 1)
            s3[i] = rand() % ('c' - 'a') + 'a';
        if (i < N / 5 - 1)
            s4[i] = rand() % ('c' - 'a') + 'a';
        if (i < N / 10 - 1)
            s5[i] = rand() % ('c' - 'a') + 'a';
    }
    PF pf2, pf3, pf4, pf5;
    pf2.Init(s2);
    pf3.Init(s3);
    pf4.Init(s4);
    pf5.Init(s5);
    cout << s2 << endl;
    for (int i = 0; i < pf2; i++)
        cout << pf2[i];
    cout << endl << "Кол-во сравнений при N = 100: " << pf2.CmpCount() << endl << endl;
    cout << s3 << endl;
    for (int i = 0; i < pf3; i++)
        cout << pf3[i];
    cout << endl << "Кол-во сравнений при N = 50: " << pf3.CmpCount() << endl << endl;
    cout << s4 << endl;
    for (int i = 0; i < pf4; i++)
        cout << pf4[i];
    cout << endl << "Кол-во сравнений при N = 20: " << pf4.CmpCount() << endl << endl;
    cout << s5 << endl;
    for (int i = 0; i < pf5; i++)
        cout << pf5[i];
    cout << endl << "Кол-во сравнений при N = 10: " << pf5.CmpCount() << endl << endl;
    return 0;
}