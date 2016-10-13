#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

struct Query
{
	int left;
	int right;
	int index;
	
	bool operator < (const Query &other) const
	{
		return right < other.right;
	}
};

const int N = (1 << 20);
int a[N];
int xorSum[N];
Query q[N];
int ans[N];


struct SegmentTree
{
	SegmentTree()
	{
		fill(array, array + N + N, 0);
	}
	
	void update(int i, int value)
	{
		for (i += N - 1; i > 0; i /= 2)
		{
			array[i] ^= value;
		}
	}
	
	int query(int left, int right)
	{
		int res = 0;
		
		for (left += N - 1, right += N; left != right; left /= 2, right /= 2)
		{
			if (left & 1)
			{
				res ^= array[left++];
			}
			if (right & 1)
			{
				res ^= array[--right];
			}
		}
		
		return res;
	}
	
	int array[N + N];
} tr;

int main()
{
	int n, m, i, j;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &q[i].left, &q[i].right);
		q[i].index = i;
	}
	
	sort(q + 1, q + 1 + m);
	
	
	map<int, int> last;
	for (i = 1, j = 1; i <= n; i++)
	{
		int &lastTmp = last[a[i]];
		if (lastTmp > 0)
		{
			tr.update(lastTmp, a[i]);
		}
		lastTmp = i;
		tr.update(i, a[i]);
		xorSum[i] = xorSum[i - 1] ^ a[i];
		
		for (; j <= m && q[j].right == i; j++)
		{
			ans[q[j].index] = xorSum[i] ^ xorSum[q[j].left - 1] ^ tr.query(q[j].left, q[j].right);
		}
	}
	
	for (i = 1; i <= m; i++)
	{
		printf("%d\n", ans[i]);
	}
	
	return 0;
}