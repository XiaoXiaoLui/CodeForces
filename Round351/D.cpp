#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int getCase(int a, int b, int c, int d)
{	
	if (a != c && b != d)
	{
		return 0;
	}
	else if (a == c && b != d )
	{
		return 1;
	}
	else if (a != c && b == d)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

const int N = 1002;
int s1[N];
int s2[N];

int main()
{
	int n, k, i, len1, len2;
	int a, b, c, d, ca;
	bool ok = true;
	bool swap1 = false;
	bool swap2 = false;
	cin >> n >> k >> a >> b >> c >> d;
	
	len1 = 0;
	len2 = 0;
	if (a > b)
	{
		swap(a, b);
		swap1 = true;
	}
	if (c > d)
	{
		swap(c, d);
		swap2 = true;
	}
	
	ca = getCase(a, b, c, d);
	

	if ((ca == 0 && (k < n+1 || n == 4)) || (ca < 3 && k < n))
	{
		cout << -1 << endl;
		goto END;
	}
	else if (ca == 0)
	{
		s1[len1++] = a;
		s1[len1++] = c;
		for (i = 1; i <= n; i++)
		{
			if (i != a && i != b && i != c && i != d)
			{
				s1[len1++] = i;
			}
		}
		s1[len1++] = d;
		s1[len1++] = b;
		
		s2[len2++] = c;
		s2[len2++] = a;
		for (i = 1; i <= n; i++)
		{
			if (i != a && i != b && i != c && i != d)
			{
				s2[len2++] = i;
			}
		}
		s2[len2++] = b;
		s2[len2++] = d;
	}
	else if (ca == 1)
	{
		s1[len1++] = a;
		for (i = 1; i <= n; i++)
		{
			if (i != a && i != b && i != d)
			{
				s1[len1++] = i;
			}
		}
		s1[len1++] = d;
		s1[len1++] = b;
		
		s2[len2++] = c;
		for (i = 1; i <= n; i++)
		{
			if (i != c && i != d && i != b)
			{
				s2[len2++] = i;
			}
		}
		s2[len2++] = b;
		s2[len2++] = d;
	}
	else if (ca == 2)
	{
		s1[len1++] = a;
		s1[len1++] = c;
		for (i = 1; i <= n; i++)
		{
			if (i != c && i != b)
			{
				s1[len1++] = i;
			}
		}
		s1[len1++] = b;
		
		s2[len2++] = c;
		s2[len2++] = a;
		for (i = 1; i <= n; i++)
		{
			if (i != c && i != a && i != b)
			{
				s2[len2++] = i;
			}
		}
		s2[len2++] = d;
	}
	else
	{
		s1[len1++] = s2[len2++] = a;
		
		for (i = 1; i <= n; i++)
		{
			if (i != a && i != b)
			{
				s1[len1++] = s2[len2++] = i;
			}
		}
		s1[len1++] = s2[len2++] = b;
	}


	
	
	
	if (swap1)
	{
		for (i = len1 - 1; i >= 0; i--)
		{
			cout << s1[i] << " ";
		}
	}
	else
	{
		for (i = 0; i < len1; i++)
		{
			cout << s1[i] << " ";
		}
	}
	cout << endl;
	
	
	if (swap2)
	{
		for (i = len2 - 1; i >= 0; i--)
		{
			cout << s2[i] << " ";
		}
	}
	else
	{
		for (i = 0; i < len2; i++)
		{
			cout << s2[i] << " ";
		}
	}
	cout << endl;
	
END:
	return 0;
}