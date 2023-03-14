#include "Aggregate.h"
#include <iostream>
Aggregate::Aggregate()
{
	m_objTest.nCount++;
	std::cout << "Create_Aggreagate_Object" << std::endl;
}
Aggregate::~Aggregate()
{
	m_objTest.nCount--;
	std::cout << "Delete_Aggreagate_Object" << std::endl;
}