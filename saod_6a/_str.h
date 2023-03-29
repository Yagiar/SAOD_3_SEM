#pragma once
#include <string.h>
using namespace std;
class Str;
class _str
{
	char* m_pszData;
	int m_nCount;
	friend class Str;
	_str()
	{
		m_pszData = new char[1] {0};
		m_nCount = 1;
	}
	_str(const char* p)
	{
		m_nCount = 1;
		m_pszData = new char[strlen(p) + 1];
		strcpy_s(m_pszData, strlen(p) + 1, p);
	}
	~_str()
	{
		delete[] m_pszData;
	}
	void AddRef()
	{
		m_nCount++;
	}
	void Release()
	{
		m_nCount--;
		if (m_nCount == 0)
			delete this;
	}
};