#include <iostream>
#include <cmath>
#include "Complex.h"

using namespace std;

int main()
{
	Complex c;
	cout<< c << endl;
	Complex a(1, 2), b = 10;
	cout << a << ", " << b << endl;
	Complex plus = b + 6, minus = b - 6, multiply = b * 3, del = b / 5, PlusMin = 0 + 6 - 6, MultDel = 5 * 2 / 2, HugeDel = 5 / 5;
	cout << plus << " " << minus << " " << multiply << " " << del << endl;
	cout << PlusMin << " " << MultDel << " " << HugeDel << endl;
	cout << a.Conjugate() << endl;
	cout << a.Mod() << endl;
	cout << a.Arg() << endl;
	Complex v[4]{ 1,2, Complex(2,3) };
	for (int i = 0; i < 4; i++)
		cout << v[i];
	cout << endl;
	Complex *pc = new Complex(1,2);
	cout << *pc << endl;
	double x = pc->Re;
	double y = pc->Im;
	delete pc;
	cout << x << " " << y << endl;
	Complex* pk = new Complex[3]{ 1,(4,8) };
	cout << pk[1].Re;
	delete[] v, pk;
}