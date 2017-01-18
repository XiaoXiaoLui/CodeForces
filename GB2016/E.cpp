// include stdc++.h slows down compilation much.
//#include<bits/stdc++.h>
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

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

typedef int State[5][5];

const int N = 1 << 18;
const int INF = 1e8;

State tr[2*N];
char s[N];
int n;

void resetState(State a)
{
	fill_n((int*)a, 25, INF);
	for (int i = 0; i < 5; i++)
	{
		a[i][i] = 0;
	}
}

void setState(State a, char ch)
{
	resetState(a);
	
	switch (ch)
	{
	case '0':
		a[1][1] = 1;
		a[1][2] = 0;
		break;
	case '1':
		a[2][2] = 1;
		a[2][3] = 0;
		break;
	case '2':
		a[0][0] = 1;
		a[0][1] = 0;
		break;
	case '6':
		a[3][3] = 1;
		a[4][4] = 1;
		break;
	case '7':
		a[3][3] = 1;
		a[3][4] = 0;
		break;
	}
}


void merge(State res, State left, State right)
{
	int i, j, k;
	State tmp;
	for (i = 0; i < 5; i++)
	{
		for (j = i; j < 5; j++)
		{
			tmp[i][j] = INF;
			for (k = i; k <= j; k++)
			{
				tmp[i][j] = min(tmp[i][j], left[i][k] + right[k][j]);
			}
		}
	}
	
	memcpy(res, tmp, sizeof(State));
}

// tr[id] contains [left, right]
void buildSegTree()
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (i < n)
		{
			setState(tr[i + N], s[i]);
		}
		else
		{
			resetState(tr[i + N]);
		}
	}
	
	for (i = N - 1; i >= 1; i--)
	{
		merge(tr[i], tr[2*i], tr[2*i + 1]);
	}
}

int query(int left, int right)
{
	State lState, rState;
	int l, r;
	resetState(lState);
	resetState(rState);
	for (l = left + N, r = right + N + 1; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
		{
			merge(lState, lState, tr[l++]);
		}
		
		if (r & 1)
		{
			merge(rState, tr[--r], rState);
		}
	}
	
	
	State res;
	merge(res, lState, rState);
	return res[0][4] >= INF ? -1 : res[0][4];
}

int l[N];
int r[N];
int ans[N];

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	#endif
	int i, qNum;
	tr[10][0][0] = 10;
	scanf("%d%d", &n, &qNum);
	scanf("%s", s);
	for (i = 1; i <= qNum; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		l[i]--;
		r[i]--;
	}
	
	buildSegTree();
	for (i = 1; i <= qNum; i++)
	{
		ans[i] = query(l[i], r[i]);
	}
	for (i = 1; i <= qNum; i++)
	{
		printf("%d\n", ans[i]);
	}
	
	return 0;
}