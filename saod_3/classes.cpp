#include <iostream>
#include <cmath>
#include "Complex.h"

using namespace std;

int main()
{
	Complex c;
	cout<< c << endl;
	Complex first(4, 3), b = 5;
	cout << first << ", " << b << endl;
	Complex plus = b + 2, minus = b - 2, multiply = b * 5 del = b / 3, PlusMin = 0 + 6 - 6, MultDel = 5 * 2 / 2, YourselfDel = 5 / 5;
	cout << plus << " " << minus << " " << multiply << " " << del << endl;
	cout << PlusMin << " " << MultDel << " " << YourselfDel << endl;
	cout << first.Conjugate() << endl;
	cout << first.Mod() << endl;
	cout << first.Arg() << endl;
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