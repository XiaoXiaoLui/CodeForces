#include <iostream>
//#include <set>
#include <string>

using namespace std;

/*
struct Item
{
	int index;
	int type;
	int x;
	
	bool operator < (const Item &other) const
	{
		return index < other.index;
	}
};*/

const int N = 2005;

int index[N][2];
bool used[5002];
int best[N];
int exp2[N];
int len1;
int ans[N];
int len2;

void add(int a[], int &lenA, int b[], int lenB)
{
	int i, r, c, end;
	end = max(lenA, lenB);
	
	for (i = 0, r = 0, c = 0; i <= end; i++)
	{
		r = (a[i] + b[i] + c) % 10;
		c = (a[i] + b[i] + c) / 10;
		a[i] = r;
	}
	
	if (c)
	{
		a[i] = c;
		lenA = i + 1;
	}
	else
	{
		lenA = i;
	}
}

void ax2(int a[], int &lenA)
{
	int i, r, c;
	
	for (i = 0, r = 0, c = 0; i < lenA; i++)
	{
		r = (a[i] * 2 + c) % 10;
		c = (a[i] * 2 + c) / 10;
		a[i] = r;
	}
	
	if (c)
	{
		a[i] = c;
		lenA = i + 1;
	}
	else
	{
		lenA = i;
	}
}

int main()
{
	int n, i, x;
	string type;
	int index1, index2;
	
	cin >> n;
	
	for (i = 1; i <= n; i++)
	{
		cin >> type;
		cin >> x;
		
		if (type == "sell")
		{
			index[x][1] = i;
		}
		else if (index[x][1] == 0)
		{
			index[x][0] = i;
		}
	}
	
	bool ok;
	for (x = N - 2; x >= 0; x--)
	{
		if (index[x][0] && index[x][1] && index[x][0] < index[x][1])
		{
			index1 = index[x][0];
			index2 = index[x][1];
			
			ok = true;
			for (i = index1; i <= index2; i++)
			{
				if (used[i])
				{
					ok = false;
					break;
				}
			}
			
			if (ok)
			{
				best[x] = 1;
				for (i = index1; i <= index2; i++)
				{
					used[i] = true;
				}
			}
		}
	}
	
	exp2[0] = 1;
	len1 = 1;
	len2 = 1;
	for (i = 0; i < N - 4; i++)
	{
		if (best[i])
		{
			add(ans, len1, exp2, len2);
		}
		ax2(exp2, len2);
	}
	
	for (i = len1 - 1; i > 0 && ans[len1 - 1] == 0; i--)
	{
		len1--;
	}
	for (i = len1 - 1; i >= 0; i--)
	{
		cout << ans[i];
	}
	cout << endl;
	
	return 0;
}
