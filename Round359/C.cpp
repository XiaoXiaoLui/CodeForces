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

const int BASE = 7;
int hour[40];
int minute[40];
int hLen;
int mLen;
int len;
bool init(int n, int m)
{
	while (n)
	{
		hour[hLen++] = n % BASE;
		n /= BASE;
	}
	hLen = max(hLen, 1);
	
	while (m)
	{
		minute[mLen++] = m % BASE;
		m /= BASE;
	}
	mLen = max(mLen, 1);
	len = mLen + hLen;
	
	int i;
	for (i = 0; i < hLen / 2; i++)
	{
		swap(hour[i], hour[hLen - 1 - i]);
	}
	
	for (i = 0; i < mLen / 2; i++)
	{
		swap(minute[i], minute[mLen - 1 - i]);
	}
	
	return (len <= BASE);
}

int permu(int a, int b)
{
	int res = 1;
	for (int i = 1; i <= b; i++)
	{
		res *= a;
		a--;
	}
	return res;
}

//
int ans;
int cal(int i, int j, int base)
{
	int tmpH[40];
	int tmpM[40];
	int k;
	int res = 0;
	bool ok;
	
	if (hLen - i + mLen - j > base)
	{
		return 0;
	}
	if (i == hLen && j == hLen)
	{
		return 1;
	}
	
	if (i < hLen && hour[i] > 0)
	{
		memcpy(tmpH, hour, sizeof(hour));
		for (k = i + 1; k < hLen; k++)
		{
			hour[k] = base - 1;
		}
		res += (hour[i] - 1) * cal(i + 1, j, base - 1);
		memcpy(hour, tmpH, sizeof(hour));
	}
	if (j < mLen && minute[j] > 0)
	{
		memcpy(tmpM, minute, sizeof(minute));
		for (k = j + 1; k < mLen; k++)
		{
			minute[k] = base - 1;
		}
		res += (minute[j] - 1) * cal(i, j + 1, base - 1);
		memcpy(minute, tmpM, sizeof(minute));
	}
	
	memcpy(tmpH, hour, sizeof(hour));
	ok = i < hLen;
	for (k = i + 1; k < hLen; k++)
	{
		if (hour[k] >= hour[i])
		{
			hour[k]--;
			if (hour[k] < 0)
			{
				ok = false;
				break;
			}
		}
	}
	if (ok)
	{
		res += cal(i + 1, j, base - 1);
	}
	memcpy(hour, tmpH, sizeof(hour));
	
	memcpy(tmpM, minute, sizeof(minute));
	ok = j < mLen;
	for (k = j + 1; k < mLen; k++)
	{
		if (minute[k] >= minute[j])
		{
			minute[k]--;
			if (minute[k] < 0)
			{
				ok = false;
				break;
			}
		}
		
	}
	if (ok)
	{
		res += cal(i, j + 1, base - 1);
	}
	memcpy(minute, tmpM, sizeof(minute));
	
	return res;
}

int main()
{
	int n, m, i, j, k, l;
	bool ok = true;
	
	scanf("%d%d", &n, &m);
	
	ok = init(n - 1, m - 1);
	
	if (ok)
	{
		ans = cal(0, 0, BASE);
	}
	
	
	
	printf("%d\n", ans);
	return 0;
}