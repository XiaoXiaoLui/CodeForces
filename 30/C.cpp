#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Target
{
	double x;
	double y;
	double t;
	double p;
};

const int N = 1005;


int n;
vector<int> in[N];
Target target[N];
double f[N];
bool visit[N];

double sqr(double x)
{
	return x*x;
}

double dist(int i, int j)
{
	return sqrt(sqr(target[i].x - target[j].x) + sqr(target[i].y - target[j].y));
}

void dfs(int u)
{
	visit[u] = true;
	double best = target[u].p;
	int i, v;
	for (i = 0; i < in[u].size(); i++)
	{
		v = in[u][i];
		if (!visit[v])
		{
			dfs(v);
		}
		best = max(best, f[v] + target[u].p);
	}
	f[u] = best;
}

int main()
{
	scanf("%d",  &n);
	int i, u, v;
	double ans = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%lf%lf%lf%lf", &target[i].x, &target[i].y, &target[i].t, &target[i].p);
	}
	
	for (u = 1; u <= n; u++)
	{
		for (v = 1; v <= n; v++)
		{
			if (u == v)
			{
				continue;
			}
			if (target[u].t + dist(u, v) <= target[v].t)
			{
				in[v].push_back(u);
			}
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			dfs(i);
		}
		ans = max(ans, f[i]);
	}
	
	printf("%.9lf\n", ans);
	
	
	return 0;
}