#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
#define mp make_pair<int, int>

//const int N = 1e5 + 5;


int hLen;
int mLen;
bool init(int n, int m)
{
	while (n && hLen <= 7)
	{
		n /= 7;
		hLen++;
	}
	hLen = max(hLen, 1);
	
	while (m && mLen <= 7)
	{
		mLen++;
		m /= 7;
	}
	mLen = max(mLen, 1);
	
	return (hLen + mLen <= 7);
}

int a[8];

bool check(int n, int m)
{
	int hour, minute, i;
	for (i = 0, hour = 0; i < hLen; i++)
	{
		hour = hour * 7 + a[i];
	}
	
	for (minute = 0; i < hLen + mLen; i++)
	{
		minute = minute * 7 + a[i];
	}
	
	return hour < n && minute < m;
}

int main()
{
	int n, m, i, j, k, l;
	int ans = 0;
	bool ok = true;
	
	scanf("%d%d", &n, &m);
	
	ok = init(n - 1, m - 1);
	
	if (ok)
	{
		int len = hLen + mLen;
		for (i = 0; i < 7; i++)
		{
			a[i] = i;
		}
		do
		{
			if (check(n, m))
			{
				ans++;
			}
		} while (next_permutation(a, a + 7));
		
	}
	
	int f = 7 - mLen - hLen;
	while (f && ok)
	{
		ans /= f;
		f--;
	}
	
	printf("%d\n", ans);
	return 0;
}