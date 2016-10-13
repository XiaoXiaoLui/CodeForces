#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

int a[50][50];
pii seq[20];
char s[20];
int main()
{
	int n, i, j, ii, jj, k, digit;
	scanf("%d", &n);
	scanf("%s", s);
	for (i = 0; i < n; i++)
	{
		digit = s[i] - '0';
		if (digit == 0)
		{
			ii = 4;
			jj = 2;
		}
		else
		{
			ii = (digit - 1) / 3 + 1;
			jj = (digit - 1) % 3 + 1;
		}
		seq[i] = mp(ii, jj);
	}
	
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			a[i][j] = 1;
		}
	}
	a[4][2] = 1;
	
	int count = 0;
	bool ok;
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			ok = true;
			ii = i;
			jj = j;
			for (k = 0; k < n; k++)
			{
				if (ii < 1 || jj < 1 || !a[ii][jj])
				{
					ok = false;
					break;
				}
				ii = ii + seq[k + 1].first - seq[k].first;
				jj = jj + seq[k + 1].second - seq[k].second;
			}
			if (ok)
			{
				count++;
			}
		}
	}
	
	if (count == 1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	return 0;
}