#include <iostream>
#include "Test.h"
int Test::nCount = 0;
	Test::Test()
	{
		TestNumber = 0;
		nCount++;
		std::cout << "Create_Test_Object" << std::endl;
	}
	Test::Test(const Test& t)
	{
		TestNumber = 1;
		nCount++;
		std::cout << "Create_Test_Same_Object" << std::endl;
	}
	Test::~Test()
	{
		nCount--;
		std::cout << "Delete_Test_Object" << std::endl;
	}