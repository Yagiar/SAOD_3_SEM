#include <iostream>
#include "utils.h"
using namespace std;

int main()
{
	char str[] = "Hello!";
	cout << str << endl;
	cout << strlen(str) << ' ' << sizeof(str) << endl;//sizeof занимаемый объем памяти,strlen длина строки.
	char t[32];
	for (char* pd = t, *ps = str; *pd++ = *ps++;);
	for (int i = 0; i < strlen(str); i++)
	{
		cout << t[i];
	}
	//более понятно
	char* pd = t;
	char* ps = str; 

	while (*ps != '\0') { 
		*pd = *ps;
		pd++;
		ps++;
	}

	*pd = '\0'; 
	//вынесем это в фукнцию string_copy
	cout << endl << "My_Len: " << len(str) << endl;;
	cout << "My_Compare: " << compare(t, str);
}