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

//#define DEBUG

typedef long long ll;

struct Query
{
	void init(int a, int b, int i)
	{
		this->a = a;
		this->b = b;
		this->index = i;
	}
	
	bool operator < (const Query &other) const
	{
		if (b != other.b)
		{
			return b < other.b;
		}
		
		return (a % b) < (other.a % b);
	}
	
	int a;
	int b;
	int index;
};


const int N = 3e5 + 5;
Query q[N];
int w[N];
ll sum[N];
ll ans[N];

int main()
{
	int n, m, i, a, b, j, lastIndex, d, start, index;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		q[i].init(a, b, i);
	}
	sort(q, q + m);
	fill(sum, sum + N, 0LL);
	ll count = 0LL;
	ll maxCount = 1e9;
	for (i = 0; i < m; i++)
	{
		d = q[i].b;
		start = q[i].a % d;
		if (start == 0)
		{
				start = d;
		}
		
		if (i == 0 || q[i].b != q[i - 1].b || q[i].a % q[i].b != q[i - 1].a % q[i - 1].b)
		{			
			sum[start] = w[start];
			for (j = start + d; j <= n; j += d)
			{
				/*
				if (j != start)
				{
					sum[j] = sum[j - d] + w[j];
				}
				else
				{
					sum[j] = w[j];
				}*/
				sum[j] = sum[j - d] + w[j];
#ifdef DEBUG
				count++;
#endif
			}
			lastIndex = j - d;
		}
		
		index = q[i].index;
		if (q[i].a == start)
		{
			ans[index] = sum[lastIndex];
		}
		else
		{
			ans[index] = sum[lastIndex] - sum[q[i].a - d];
		}
	
// No need to reset sum array as each needed element will be recalculate	
/*
		if (i < m - 1 && (q[i].b != q[i + 1].b || q[i].a % q[i].b != q[i + 1].a % q[i + 1].b))
		{

			for (j = start; j <= n; j += d)
			{
				sum[j] = 0LL;			
#ifdef DEBUG
				count++;
#endif
			}
		}
#ifdef DEBUG
		if (count > maxCount)
		{
			break;
		}
#endif
*/
		
	}

#ifdef DEBUG
	if (count > maxCount)
	{
		printf(LLD "\n", count);
	}
#endif

	for (i = 0; i < m; i++)
	{
		printf(LLD "\n", ans[i]);
	}
	
	printf("\n");
	return 0;
}