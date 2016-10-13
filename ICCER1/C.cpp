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

const int N = 1e5 + 100;

struct Segment
{
	Segment() : left(0), right(0), sum(0)
	{
	}
	
	Segment(int l, int r, ll s) : left(l), right(r), sum(s)
	{
		
	}
	
	int left;
	int right;
	ll sum;
	
	bool operator < (const Segment &other) const
	{
		if (sum != other.sum)
		{
			return sum < other.sum;
		}
		
		return left < other.left;
	}
};

ll sum[N];
set<Segment> sumSet;
set<int> delSet;
map<pii, ll> sMap;
vector<ll> ans;
int a[N];
int b[N];


int main()
{
	int n, i, idx, left, right;
	ll  leftSum, rightSum, tmpSum;
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	sum[n + 1] = sum[n];
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
	}
	
	set<int>::iterator iter;
	delSet.insert(0);
	delSet.insert(n + 1);
	
	sumSet.insert(Segment(0, n + 1, sum[n]));
	sMap[mp(0, n + 1)] = sum[n];
	
	for (i = 1; i <= n; i++)
	{
		idx = b[i];
		iter = delSet.upper_bound(idx);
		right = *iter;
		iter--;
		left = *iter;
		delSet.insert(idx);
		
		tmpSum = sMap[mp(left, right)];
		Segment tmpSeg(left, right, tmpSum);
		sumSet.erase(tmpSeg);
		
		leftSum = sum[idx - 1] - sum[left];
		rightSum = sum[right - 1] - sum[idx];
		sumSet.insert(Segment(left, idx, leftSum));
		sumSet.insert(Segment(idx, right, rightSum));
		sMap[mp(left, idx)] = leftSum;
		sMap[mp(idx, right)] = rightSum;
		
		
		ans.push_back(sumSet.rbegin()->sum);
	}
	
	for (i = 0; i < ans.size(); i++)
	{
		printf("%lld\n", ans[i]);
	}
	
	return 0;
}