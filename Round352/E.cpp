#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll ans;
int n;
const int N = 200000;
map<int, int> mapNext;
int a[N + 2];
ll sum;
ll h[N + 2];
vector<int> bucket[N + 2];
vector<int> v[N + 2];

void add(int x, int y)
{
	if (x > n)
	{
		return;
	}
	map<int, int>::iterator iter1, iter2;
	ll px, py;
	iter1 = mapNext.upper_bound(x);
	
	if (iter1 == mapNext.begin())
	{
		return;
	}
	iter2 = iter1;
	iter1--;
	if (iter1->second >= y)
	{
		return;
	}
	
	//sum -= (iter2.first - x) * (ll)iter1->second;
	
	px = x;
	py = iter1->second;
	mapNext[x] = y;
	while (1)
	{
		iter1 = mapNext.upper_bound(x);
		sum -= (iter1->first - px) * py;
		px = iter1->first;
		py = iter1->second;
		if (iter1->second >= y)
		{
			sum += (iter1->first - x) * (ll)y;
			break;
		}
		mapNext.erase(iter1);
	}
}

int main()
{
	int i, j, len;
	cin >> n;
	
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		bucket[a[i]].push_back(i);
	}
	
	for (i = 1; i <= N; i++)
	{
		for (j = i; j <= N; j += i)
		{
			for (vector<int>::iterator iter = bucket[j].begin(); iter != bucket[j].end(); iter++)
			{
				v[i].push_back(*iter);
			}
		}
	}
	
	for (i = 1; i <= n + 1; i++)
	{
		mapNext[i] = i;
	}
	sum = (ll)n * (n + 1) / 2;
	
	for (i = N + 1; i >= 1; i--)
	{
		if (v[i].size() < 2)
		{
			h[i] = (ll)n * (n + 1)  - sum;
			continue;
		}
		sort(v[i].begin(), v[i].end());
		len = v[i].size();
		
		add(1, v[i][len - 2]);
		add(v[i][0] + 1, v[i][len - 1]);
		add(v[i][1] + 1, n + 1);
		h[i] = (ll)n * (n + 1)  - sum;
	}
	
	for (i = 2; i <= N + 1; i++)
	{
		ans += (h[i] - h[i - 1]) * (i - 1);
	}
	
	cout << ans << endl;
	
	return 0;
}