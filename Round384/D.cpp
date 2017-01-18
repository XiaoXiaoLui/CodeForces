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

const int N = 2e5 + 100;
const ll INF = 1e18;

vector<int> graph[N];
bool visit[N];
int a[N];
ll ans = -INF;

pair<ll, ll> dfs(int u)
{
	visit[u] = true;
	ll m1 = -INF, m2 = -INF;
	
	ll sum = a[u];
	
	for (auto v : graph[u])
	{
		if (!visit[v])
		{
			auto ret = dfs(v);
			if (ret.first > m1)
			{
				m2 = m1;
				m1 = ret.first;
			}
			else if (ret.first > m2)
			{
				m2 = ret.first;
			}
			
			sum += ret.second;
		}
	}
	
	if (m2 > -INF)
	{
		ans = max(ans, m1 + m2);
	}
	
	pair<ll, ll> res;
	res.first = max(sum, m1);
	res.second = sum;
	
	return res;
}

int main()
{
	USE_IOSTREAM;
	int n, i, u, v;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (i = 1; i < n; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	dfs(1);
	
	if (ans <= -INF)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << ans << endl;
	}
	
	return 0;
}