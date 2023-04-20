#include <string>
#include <stdexcept>

using namespace std;

class PF
{
	int n;
	int* pv;
	int cmp_counter;
public:
	PF()
	{
		pv = nullptr;
		n = 0;
		cmp_counter = 0;
	}
	~PF()
	{
		delete[] pv;
	}
	void Init(const char* s)
	{
		n = strlen(s);
		pv = new int[n];
		cmp_counter = 0;
		pv[0] = 0;
		int k = 0;
		for (int i = 1; i < n; ++i)
		{
			while (k > 0 && s[k] != s[i])
			{
				k = pv[k - 1];
				cmp_counter++;
			}
			if (s[k] == s[i])
			{
				k++;
				cmp_counter++;
			}
			pv[i] = k;
		}
	}
	operator int() const
	{
		return n;
	}
	int operator [] (int i) const
	{
		if (i >= 0 && i < n)
		{
			return pv[i];
		}
		else
		{
			throw out_of_range("Index out of range");
		}
	}
	int CmpCount()
	{
		return cmp_counter;
	}
};