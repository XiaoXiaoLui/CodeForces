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
const int M = 20;

struct DisjointSet
{
	void init(int nn)
	{
		n = nn;
		for (int i = 1; i <= n; i++)
		{
			tr[i] = -1;
		}
	}
	
	void merge(int u, int v)
	{
		int p1 = find(u);
		int p2 = find(v);
		if (tr[p1] <= tr[p2])
		{
			tr[p1] += tr[p2];
			tr[p2] = p1;
		}
		else
		{
			tr[p2] += tr[p1];
			tr[p1] = p2;
		}
	}
	
	int find(int uu)
	{
		int u, p;
		u = uu;
		while (tr[u] > 0)
		{
			u = tr[u];
		}
		
		p = u;
		
		for (u = uu; u != p; u = tr[u])
		{
			tr[u] = p;
		}
		
		return p;
	}
	
	int n;
	int tr[N];
} ds;

struct Edge
{
	int u;
	int v;
	int w;
	int c;
	int idx;
};

Edge e[N];
int srt[N];
bool sel[N];
vector<pii> graph[N];
int height[N];
int preEdge[N];
int st[N][M];
int rmq[N][M];
int lg[N];

bool cmp(int i, int j)
{
	return e[i].w < e[j].w;
}

void dfs(int u, int pre, int preEdgeIdx)
{
	st[u][0] = pre;
	rmq[u][0] = e[preEdgeIdx].w;
	height[u] = height[pre] + 1;
	preEdge[u] = preEdgeIdx;
	
	int v;
	for (auto p : graph[u])
	{
		v = p.first;
		if (v != pre)
		{
			dfs(v, u, p.second);
		}
	}
}

int lca(int u, int v)
{
	if (height[u] < height[v])
	{
		swap(u, v);
	}
	
	int maxLen = lg[height[u] - height[v]], i;
	for (i = maxLen; i >= 0; i--)
	{
		if (st[u][i] > 0 && height[st[u][i]] >= height[v])
		{
			u = st[u][i];
		}
	}
	
	// now u and v are at the same height
	if (u == v)
	{
		return u;
	}
	
	for (i = lg[height[u]]; i >= 0; i--)
	{
		if (st[u][i] != st[v][i])
		{
			u = st[u][i];
			v = st[v][i];
		}
	}
	
	return st[u][0];
}

int query(int u, int preU)
{
	if (u == preU)
	{
		return 0;
	}
	
	int maxLen = height[u] - height[preU];
	int k = lg[maxLen], add = maxLen - (1 << k);
	int v, i;
	for (i = k, v = u; i >= 0; i--)
	{
		if ((add >> i) & 1)
		{
			v = st[v][i];
		}
	}
	
	return max(rmq[u][k], rmq[v][k]);
}

ll cal(int i, bool bPrint = false)
{
	ll res = 0LL;
	int u, v, p;
	u = e[i].u;
	v = e[i].v;
	p = lca(u, v);
	
	int res1, res2;
	res1 = query(u, p);
	res2 = query(v, p);
	int best = max(res1, res2);
	if (res1 < res2)
	{
		swap(u, v);
	}
	
	res = -best + e[i].w - e[i].c;
	if (bPrint)
	{
		int k = lg[height[u] - height[p]], j;
		for (j = k; j >= 0; j--)
		{
			if (height[st[u][j]] > height[p] && query(st[u][j], p) == best)
			{
				u = st[u][j];
			}
		}
		sel[preEdge[u]] = false;
		sel[i] = true;
	}
	
	return res;
}

int main()
{
	// USE_IOSTREAM;
	int n, m, u, v, i, j, S, w;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &e[i].w);
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &e[i].c);
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		if (u > v)
		{
			swap(u, v);
		}
		e[i].u = u;
		e[i].v = v;
		e[i].idx = i;
		srt[i] = i;
	}
	
	scanf("%d", &S);
	for (i = 1; i <= m; i++)
	{
		e[i].c = S / e[i].c;
	}
	
	// kruskal
	sort(srt + 1, srt + 1 + m, cmp);
	ds.init(n);
	
	for (i = 1, j = 0; i < n; i++)
	{
		do 
		{
			j++;
			u = e[srt[j]].u;
			v = e[srt[j]].v;
		} while (ds.find(u) == ds.find(v));
		
		sel[srt[j]] = true;
		ds.merge(u, v);
	}
	
	for (i = 1; i <= m; i++)
	{
		if (sel[i])
		{
			graph[e[i].u].push_back(mp(e[i].v, e[i].idx));
			graph[e[i].v].push_back(mp(e[i].u, e[i].idx));
		}
	}
	
	
	
	// precal for LCA, cal height and st[u][0]
	for (i = 1; i <= m; i++)
	{
		if (sel[i])
		{
			dfs(e[i].u, 0, 0);
			break;
		}
	}
	
	// precal for sparse table, for LCA 
	lg[1] = 0;
	for (i = 2; i <= n; i++)
	{
		lg[i] = lg[i >> 1] + 1;
	}
	
	for (j = 1; j <= lg[n - 1]; j++)
	{
		for (i = 1; i <= n; i++)
		{
			if (st[i][j - 1] > 0)
			{
				st[i][j] = st[st[i][j - 1]][j - 1];
				rmq[i][j] = max(rmq[i][j - 1], rmq[st[i][j - 1]][j - 1]);
			}
		}
	}
	
	

	// try every edge
	ll minSum = 1e18, tmp;
	int minIdx = 0;
	
	for (i = 1; i <= m; i++)
	{
		tmp = cal(i);
		if (tmp < minSum)
		{
			minIdx = i;
			minSum = tmp;
		}
	}
	
	// get the best answer
	cal(minIdx, true);
	
	vector<pii> ansVec;
	minSum = 0LL;
	for (i = 1; i <= m; i++)
	{
		if (sel[i])
		{
			w = (i == minIdx) ? e[i].w - e[i].c : e[i].w;
			ansVec.push_back(mp(i, w));
			minSum += w;
		}
	}
	
	printf("%lld\n", minSum);
	for (auto tmp : ansVec)
	{
		printf("%d %d\n", tmp.first, tmp.second);
	}
	
	return 0;
}