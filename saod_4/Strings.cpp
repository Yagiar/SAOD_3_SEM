#include <iostream>
#include "Str.h"
using namespace std;
void Test(Str s) {};
int main()
{
	Str s ;
	cout << "Write s: ";
	cin >> s;
	cout << s << endl;
	cout <<"Len: " << strlen(s) << endl;//проверка strlen`а
	Test(s);
	cout <<"Test: " <<s << endl;
	Str t;
	t = s;
	s = "";
	t = "";
	cout << "Cin two str" << endl;
	cin >> s >> t;
	s += t;
	cout <<"s+=t: " << s << endl;// проверка +=
	Str x = "1", y = "2";
	Str nine =  x+y ;
	cout <<"Plus nine= x+y: " << nine;
	return 0;
}