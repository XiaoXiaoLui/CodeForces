#include<bits/stdc++.h>

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

const int N = 1 << 19;

struct Node
{
	int leftLen;
	int rightLen;
	int len;
};

ll a[N];
Node tr[N*2];
int ans[N];

int sign(ll num)
{
	if (!num)
	{
		return 0;
	}
	
	return num > 0 ? 1 : -1;
}

void merge(int id, int l, int r)
{
	int mid = (l + r) / 2;
	int leftId = 2*id;
	int rightId = 2*id + 1;
	tr[id].len = max(tr[leftId].len, tr[rightId].len);
	if (!a[mid] || !a[mid + 1] || sign(a[mid]) < sign(a[mid + 1]))
	{
		tr[id].leftLen = tr[leftId].leftLen;
		tr[id].rightLen = tr[rightId].rightLen;
	}
	else
	{
		tr[id].len = max(tr[id].len, tr[leftId].rightLen + tr[rightId].leftLen);
		if (tr[leftId].leftLen == mid - l + 1)
		{
			tr[id].leftLen = tr[leftId].leftLen + tr[rightId].leftLen;
		}
		else
		{
			tr[id].leftLen = tr[leftId].leftLen;
		}
		
		if (tr[rightId].rightLen == r - mid)
		{
			tr[id].rightLen = tr[rightId].rightLen + tr[leftId].rightLen;
		}
		else
		{
			tr[id].rightLen = tr[rightId].rightLen;
		}
	}
}

void build(int id, int l, int r)
{
	if (l == r)
	{
		int x = (a[l] ? 1 : 0);
		tr[id] = {x, x, x};
	}
	else
	{
		int mid = (l + r) / 2;
		build(2*id, l, mid);
		build(2*id + 1, mid + 1, r);
		merge(id, l, r);
	}
}

void update(int id, int l, int r, int pos, int val)
{
	if (l == r)
	{
		a[pos] += val;
		int x = (a[pos] ? 1 : 0);
		tr[id] = {x, x, x};
	}
	else
	{
		int mid = (l + r) / 2;
		if (pos <= mid)
		{
			update(2*id, l, mid, pos, val);
		}
		else
		{
			update(2*id + 1, mid + 1, r, pos, val);
		}
		merge(id, l, r);
	}
}

int main()
{
	// USE_IOSTREAM;
	int n, m, i, left, right, d;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for (i = 1; i < n; i++)
	{
		a[i] = a[i + 1] - a[i];
	}
	
	scanf("%d", &m);
	n--;
	if (n)
	{
		build(1, 1, n);
	}
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &left, &right, &d);
		if (!n)
		{
			ans[i] = 1;
			continue;
		}
		
		if (left != 1)
		{
			update(1, 1, n, left - 1, d);
		}
		if (right <= n)
		{
			update(1, 1, n, right, -d);
		}
		ans[i] = tr[1].len + 1;
	}
	
	for (i = 1; i <= m; i++)
	{
		printf("%d\n", ans[i]);
	}
	
	return 0;
}