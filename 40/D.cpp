#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

// base 10000
struct BigInteger
{
	BigInteger()
	{
		memset(a, 0, sizeof(a));
		len = 1;
	}
	
	BigInteger(int num)
	{
		memset(a, 0, sizeof(a));
		a[0] = num;
		len = 1;
	}
	
	BigInteger(const string &str)
	{
		memset(a, 0, sizeof(a));
		int cur = 0;
		len = 0;
		int i, j;
		for (i = str.length() - 1, j = 0; i >= 0; i--, j++)
		{
			cur += EXP10[j % 4] * (str[i] - '0');
			
			if (j % 4 == 3 || j == str.length() - 1)
			{
				a[len++] = cur;
				cur = 0;
			}
		}
	}
	
	BigInteger operator + (const BigInteger &other) const
	{
		BigInteger res;
		int r = 0, i;
		int end = min(len, other.len);
		res.len = max(len, other.len);
		for (i = 0; i < end; i++)
		{
			res.a[i] = a[i] + other.a[i] + r;
			r = res.a[i] / M;
			res.a[i] %= M;
		}
		
		if (len >= other.len)
		{
			for (; i < len; i++)
			{
				res.a[i] = a[i] + r;
				r = res.a[i] / M;
				res.a[i] %= M;
			}
		}
		else
		{
			for (; i < other.len; i++)
			{
				res.a[i] = other.a[i] + r;
				r = res.a[i] / M;
				res.a[i] %= M;
			}
		}
		
		if (r != 0)
		{
			res.a[res.len++] = r;
		}
		
		return res;
	}
	
	BigInteger operator * (const BigInteger &other) const
	{
		BigInteger res;
		
		res.len  = len + other.len;
		int i, j, r;
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < other.len; j++)
			{
				res.a[i + j] += a[i] * other.a[j];
			}
		}
		
		r = 0;
		for (i = 0; i < res.len; i++)
		{
			res.a[i] += r;
			r = res.a[i] / M;
			res.a[i] %= M;
		}
		
		if (res.a[res.len - 1] == 0 && res.len > 1)
		{
			res.len--;
		}
		
		return res;
	}
	
	// num <= *this
	BigInteger operator - (int num) const
	{
		BigInteger res;
		int r = -num, i;
		for (i = 0; i < len; i++)
		{
			res.a[i] = a[i] + r;
			r = div(res.a[i], M);
			res.a[i] = mod(res.a[i], M);
		}
		
		res.len = len;
		if (res.a[len - 1] == 0)
		{
			res.len--;
		}
		return res;
	}
	
	BigInteger operator / (int num) const
	{
		BigInteger res;
		int r = 0, i;
		int cur = 0;
		for (i = len - 1; i >= 0; i--)
		{
			cur = r * M + a[i];
			res.a[i] = cur / num;
			r = cur % num;
		}
		
		for (i = len - 1; i >= 0; i--)
		{
			if (res.a[i])
			{
				break;
			}
		}
		res.len = max(i + 1, 1);
		return res;
	}
	
	int operator % (int num) const
	{
		int r = 0, i;
		int cur = 0;
		for (i = len - 1; i >= 0; i--)
		{
			cur = r * M + a[i];
			r = cur % num;
		}
		
		return r;
	}
	
	void print()
	{
		for (int i = len - 1; i >= 0; i--)
		{
			if (i != len - 1)
			{
				cout << setfill('0') << setw(4) << a[i];
			}
			else
			{
				cout << a[i];
			}
		}
		cout << endl;
	}
	
	bool noneZero() const
	{
		return (len > 1 || a[0]);
	}
	
	int getLen()
	{
		return len;
	}
private:
	/*
	a = qb + r
	abs(r) < b
	
	default operator '/':
	-a / b = a / -b = -(a/b), that is ,just cut the decimal_point
	
	here we need a division more like math, r >= 0
	*/
	static int div(int a, int b)
	{
		int q = a / b;
		if (b * q > a)
		{
			if (b < 0)
			{
				q++;
			}
			else
			{
				q--;
			}
		}
		
		return q;
	}
	
	static int mod(int a, int b)
	{
		int q = div(a, b);
		return a - b*q;
	}
	
	const static int M = 10000;
	const static int N = 800;
	const static int EXP10[4];
	
	int a[N];
	int len;
};

const int BigInteger::EXP10[4] = {1, 10, 100, 1000};

BigInteger exp12[605];

const int M = 12;
int main()
{
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	BigInteger A(str);
	
	int i, j, k, n, p;
	exp12[0] = BigInteger(1);
	for (i = 1; i < 600; i++)
	{
		exp12[i] = BigInteger(12) * exp12[i - 1];
		if (exp12[i].getLen() > 700)
		{
			break;
		}
	}
	
	k = 0;
	while (A % 12 == 0 && A.noneZero())
	{
		A = A / 12;
		k++;
	}
	A = A - 1;
	j = 0;
	while (A % 12 == 0 && A.noneZero())
	{
		A = A / 12;
		j++;
	}
	
	if (!A.noneZero() || (A - 1).noneZero())
	{
		cout << "NO" << endl;
		return 0;
	}
	
	n = 2*k + j + 1;
	
	p = (n - 1) / 2;
	
	
	cout << "YES" << endl << "1" << endl << n << endl;
	cout << p << endl;
	
	for (i = p; i >= 0; i--)
	{
		if (i == k)
		{
			continue;
		}
		(exp12[i] + exp12[n - 1 - i]).print();
	}
	
	return 0;
}