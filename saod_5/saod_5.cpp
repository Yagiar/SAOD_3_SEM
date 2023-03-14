#include <iostream>
#include "Test.h"
#include"Child.h"
#include "Aggregate.h"
#include "AggregateT.h"
using namespace std;
static Test Global_Object;
void foo_Test(Test& t)
{
	Test New_U_Test = t;
	cout << "New_U_Test: Number: " << New_U_Test.TestNumber << endl;
}
int main()
{
	cout << Global_Object.nCount<<endl;
	Test h;

	cout << "Dynamic_Object" << endl;
	Test* p = new Test();
	delete p;

	cout << "Test-Array:" << endl;
	Test* Test_Array = new Test[5];
	delete[] Test_Array;

	cout << endl << "Copy_Object" << endl;
	Test U_Test;
	cout <<"U_Test: Number: " << U_Test.TestNumber << endl;
	foo_Test(U_Test);

	cout << "----------------------------------------" << endl << "Child_Class" << endl;
	Child child;// при создании объекта child создается объект Test и дальше наследуются в Child затем
	//создается объект класса child, удаление же начинается с объекта класса Child и заканчивается наследуемым
	cout << "----------------------------------------" << endl << "Aggregate_Class" << endl;
	Aggregate agre;
	// жизненный цикл точно такой же как при наследовании, только свойства не наследуются

	AggregateT<Test> aggregateTest;

	AggregateT<Child> aggregateChild;
	return 0;
}