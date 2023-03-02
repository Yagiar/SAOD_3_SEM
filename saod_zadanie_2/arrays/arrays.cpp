#include <iostream>
#include "utils.h"
using namespace std;
//void rotate(int* a, int n) {
//    int x = *a;
//    for (int i = 1; i < n; i++) {
//        *(a + i - 1) = *(a + i);
//    }
//    *(a + n - 1) = x;
//}
int main()
{
    int a[5]{ 1,2,3,4,5 };
    for (int i = 0; i < 5; i++)
        cout << a[i] << ' ';
    cout << endl;
    cout << "UKAZ" << endl;
    for (int* p = a; p - a < 5; p++)
        cout << *p << ' ';
    cout << endl;
    cout << "Rotate-UKAZ" << endl;
    rotate_clockwise(a, 5);
    for (int i = 0; i < 5; i++)
        cout << a[i] << ' ';
    cout << endl;
    cout << "Rotate-clockwise" << endl;
    rotate_clockwise(a, 5, true);
    for (int i = 0; i < 5; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
