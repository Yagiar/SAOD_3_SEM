// in-out.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cmath>
#include <bitset>
using namespace std;
int main()
{
	cout << "Hello !\n";
	unsigned int x, y, result;
	cout << "x = ? "; cin >> x; // Подсказка и ввод х
	cout << "y = ? "; cin >> y; // Подсказка и ввод y
	cout << x << " + " << y << " = " << x + y << endl;
	cout << x << " - " << y << " = " << x - y << endl;
	cout << x << " * " << y << " = " << x * y << endl;
	cout << x << " / " << y << " = " << x / y << endl;
	cout << x << " % " << y << " = " << x % y << endl;
	result = x | y;
	cout << x << " | " << y << " = " << result << endl;
	result = x & y;
	cout << x << " & " << y << " = " << result<<endl;
	cout << x << " ^ " << y << " = " << pow(x,y) << endl;
	result = x >> y;
	cout << x << " >> " << y << " = " << result << endl;
	result = x << y;
	cout << x << " << " << y << " = " << result << endl;
}