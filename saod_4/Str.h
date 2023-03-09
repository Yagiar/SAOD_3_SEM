#pragma once
#include <iostream>
#include <string>
using namespace std;
class Str {
	char* m_pszText;
public:
	Str() 	//Конструктор “по умолчанию” (default)*
	{
		m_pszText = new char[1] {0};
	}
	operator const char* ()const { return m_pszText; }
	Str(const char* p)
	{
		if (p) {
			m_pszText = new char[strlen(p) + 1];
			strcpy_s(m_pszText, strlen(p) + 1, p);
		}
		else
			m_pszText = new char[1] {0};
	}
	Str(const Str& s) //Константная ссылка на объект
	{
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
	}
	const Str& operator = (const Str& s) //Константная ссылка на объект
	{
		if (&s == this) return *this;
		delete[] m_pszText;	 //Освобождаем текущие данные					//Дальше просто копирование
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
		return *this;
	}
	friend std::istream& operator>>(istream& is, Str& str)
	{
		string tmp;
		getline(is, tmp);
		str = tmp.c_str();
		return is;
	}
	Str& operator +=(const char* sz)
	{
		if (sz)
		{
			char* newStr = new char[strlen(m_pszText) + strlen(sz) + 1];
			strcpy_s(newStr, strlen(m_pszText) + 1, m_pszText);
			strcat_s(newStr, strlen(m_pszText) + strlen(sz) + 1, sz);
			delete[] m_pszText;
			m_pszText = newStr;
		}
		return *this;
			 
	}
	Str operator +(const char* sz) const {
		if (sz)
		{
			char* newStr = new char[strlen(m_pszText) + strlen(sz) + 1];
			strcpy_s(newStr, strlen(m_pszText) + 1, *this);
			strcat_s(newStr, strlen(m_pszText) + strlen(sz) + 1, sz);
			return newStr;
		}
		
	}
	~Str() { delete[]m_pszText; }

};

