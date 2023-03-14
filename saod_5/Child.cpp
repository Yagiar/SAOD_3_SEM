#include<iostream>
#include "Child.h"
Child:: Child()
{
	nCount++;
	std::cout << "Create_Child_Object" << std::endl;
}
Child:: ~Child()
{
	nCount--;
	std::cout << "Delete_Child_Object" << std::endl;
}
