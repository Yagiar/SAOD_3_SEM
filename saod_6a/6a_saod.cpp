#include <iostream>
#include "Str.h"
using namespace std;
int main()
{
	// 1 проверка
	Str s1("Hello world");
	int result1 = s1.rfind("", 3);
	cout << result1 << endl;
	// 2 проверка
	Str s2("abaabaa");
	int result2 = s2.rfind("aa", 5);
	cout << result2 << endl;
	
	// 3 проверка
	Str s3("Hello world");
	int result3 = s3.rfind("l", 5);
	cout << result3 << endl;

	// 4 проверка
	Str s4("Hello world");
	int result4 = s4.rfind("Hello", 6);
	cout << result4 << endl;

	cout << "Count_Object: " << Str::count << endl;
	return 0;
}