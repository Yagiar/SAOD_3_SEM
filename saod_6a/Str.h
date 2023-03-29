#pragma once
#include <iostream>
#include <string>
#include"_str.h"
using namespace std;
class Str {
	
public:
	_str* m_pStr;
public:
	static int count;
	Str()
	{
		m_pStr = new _str;
		count++;
	}
	Str(const char* p)
	{
		m_pStr = new _str(p);
		count++;
	}
	~Str()
	{
		m_pStr->Release();
		count--;
	}
	int len() const
	{
		return strlen(m_pStr->m_pszData);
	}
	Str(const Str& s)
	{
		m_pStr = s.m_pStr;
		m_pStr->AddRef();
	}
	operator const char* () const
	{
		return m_pStr->m_pszData;
	}
	Str& operator = (const Str& s)
	{
		if (this != &s)
		{
			s.m_pStr->AddRef();
			m_pStr->Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}
	Str& operator += (const Str& s)
	{
		int length = len() + s.len();
		if (s.len() != 0)
		{
			_str* pstrTmp = new _str;
			delete[] pstrTmp->m_pszData;
			pstrTmp->m_pszData = new char[length + 1];
			strcpy_s(pstrTmp->m_pszData, length + 1, m_pStr->m_pszData);
			strcat_s(pstrTmp->m_pszData, length + 1, s.m_pStr->m_pszData);
			m_pStr->Release();
			m_pStr = pstrTmp;
		}
		return *this;
	}
	int rfind(const char* t, int off) const {
		if (!t) return -1; 
		int t_len = strlen(t);
		int s_len = strlen(m_pStr->m_pszData);
		if (off >= s_len) return -1; 
		if (t_len > s_len) return -1; 
		for (int i = off; i >= 0; i--) { 
			bool match = true;
			for (int j = 0; j < t_len; j++) { 
				if (m_pStr->m_pszData[i + j] != t[j]) {
					match = false;
					break;
				}
			}
			if (match) { 
				return i;
			}
		}
		return -1;
	}
};

