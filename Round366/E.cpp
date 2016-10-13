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

const int N = 1e5 + 50;
const ll MOD = 1e9 + 7;

vector<int> cls[N];
vector<int> var[N];
bool visit[N];
ll c[N][2];


int nextClause(int i, int v)
{
	int j;
	v = abs(v);
	for (j = 0; j < var[v].size(); j++)
	{
		if (var[v][j] != i)
		{
			return var[v][j];
		}
	}
	
	return 0;
}

int nextVar(int i, int v)
{
	int j;
	
	for (j = 0; j < cls[i].size(); j++)
	{
		if (abs(cls[i][j]) != abs(v))
		{
			return cls[i][j];
		}
	}
	
	return 0;
}

int findFirst(int i, bool &isCircle)
{
	int v, first;
	if (cls[i].size() == 1)
	{
		return i;
	}
	
	v = abs(cls[i][0]);
	if (var[v].size() == 1)
	{
		return i;
	}
	
	first = i;
	while (v && nextClause(i, v) != 0 && nextClause(i, v) != first)
	{
		i = nextClause(i, v);
		v = nextVar(i, v);
	}
	
	if (v && nextClause(i, v) == first)
	{
		isCircle = true;
	}
	else
	{
		isCircle = false;
	}
	
	return i;
}

void solve(int i, int count)
{
	int first, curV, preV, j, k, l, rev, rev1, rev2;
	bool isCircle = false;
	first = findFirst(i, isCircle);
	
	if (!isCircle)
	{
		ll old[2][2];
		ll cur[2][2];
		memset(old, 0, sizeof(old));
		memset(cur, 0, sizeof(cur));
		if (cls[first].size() == 1)
		{
			preV = cls[first][0];
			rev = preV < 0 ? 1 : 0;
			old[1][1 ^ rev] = 1;
			old[0][rev] = 1;
		}
		else
		{
			preV = cls[first][0];
			if (nextClause(first, preV) == 0)
			{
				preV = nextVar(first, preV);
			}
			
			rev = preV < 0 ? 1 : 0;
			old[rev][0] = 1;
			old[1 ^ rev][1] = 2;
			old[rev][1] = 1;
		}
		
		visit[first] = true;
		
		for (i = nextClause(first, preV); i; i = nextClause(i, preV))
		{
			visit[i] = true;
			curV = nextVar(i, preV);
			if (curV == 0)
			{
				preV = cls[i][0];
				rev = preV < 0 ? 1 : 0;
				for (j = 0; j < 2; j++)
				{
					for (k = 0; k < 2; k++)
					{
						cur[j][rev ^ k ^ j] += old[j][k];
						cur[j][rev ^ k ^ j] %= MOD;
					}
				}
				
			}
			else
			{
				preV = nextVar(i, curV);
				rev1 = preV < 0 ? 1 : 0;
				rev2 = curV < 0 ? 1 : 0;
				for (j = 0; j < 2; j++)
				{
					for (k = 0; k < 2; k++)
					{
						for (l = 0; l < 2; l++)
						{
							cur[l][((l ^ rev2) | (j ^ rev1)) ^ k] += old[j][k];
							cur[l][((l ^ rev2) | (j ^ rev1)) ^ k] %= MOD;
						}
					}
				}
			}
			
			
			memcpy(old, cur, sizeof(cur));
			memset(cur, 0, sizeof(cur));
			preV = curV;
			if (!preV)
			{
				break;
			}
		}
		
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 2; j++)
			{
				c[count][j] += old[i][j];
				c[count][j] %= MOD;
			}
		}
	}
	else
	{
		ll old[2][2][2];
		ll cur[2][2][2];
		memset(old, 0, sizeof(old));
		memset(cur, 0, sizeof(cur));
		curV = cls[first][0];
		preV = cls[first][1];
		rev1 = curV < 0 ? 1 : 0;
		rev2 = preV < 0 ? 1 : 0;
		
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < 2; k++)
			{
				old[j][k][(j ^ rev1) | (k ^ rev2)]++;
			}
		}
		
		visit[first] = true;
		for (i = nextClause(first, preV); i != first; i = nextClause(i, preV))
		{
			visit[i] = true;
			curV = nextVar(i, preV);
			preV = nextVar(i, curV); // for sign
			rev1 = preV < 0 ? 1 : 0;
			rev2 = curV < 0 ? 1 : 0;
			
			if (nextClause(i, curV) == first)
			{
				for (j = 0; j < 2; j++)
				{
					for (k = 0; k < 2; k++)
					{
						for (l = 0; l < 2; l++)
						{
							cur[j][k][((j ^ rev2) | (k ^ rev1)) ^ l] += old[j][k][l];
							cur[j][k][((j ^ rev2) | (k ^ rev1)) ^ l] %= MOD;
						}
					}
				}
			}
			else
			{
				for (j = 0; j < 2; j++)
				{
					for (k = 0; k < 2; k++)
					{
						for (l = 0; l < 2; l++)
						{
							for (int p = 0; p < 2; p++)
							{
								cur[j][p][((p ^ rev2) | (k ^ rev1)) ^ l] += old[j][k][l];
								cur[j][p][((p ^ rev2) | (k ^ rev1)) ^ l] %= MOD;
							}
						}
					}
				}
			}
			
			memcpy(old, cur, sizeof(cur));
			memset(cur, 0, sizeof(cur));
			preV = curV;
		}
		
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 2; j++)
			{
				for (k = 0; k < 2; k++)
				{
					c[count][k] += old[i][j][k];
					c[count][k] %= MOD;
				}
			}
		}
	}
	
}

int main()
{
	int n, m, count, i, j, k, len, u, v;
	scanf("%d%d", &n, &m);
	
	count = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &len);
		if (len == 1)
		{
			scanf("%d", &u);
			cls[i].push_back(u);
			var[abs(u)].push_back(i);
		}
		else
		{
			scanf("%d%d", &u, &v);
			if (u == v)
			{
				count++;
				visit[i] = true;
				var[abs(u)].push_back(i);
				c[count][0] = c[count][1] = 1;
			}
			else if (u == -v)
			{
				count++;
				visit[i] = true;
				var[abs(u)].push_back(i);
				c[count][0] = 0;
				c[count][1] = 2;
			}
			else
			{
				cls[i].push_back(u);
				cls[i].push_back(v);
				var[abs(u)].push_back(i);
				var[abs(v)].push_back(i);
			}
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			count++;
			solve(i, count);
		}
	}
	
	ll cur[2] = {0, 0};
	ll old[2] = {1, 0};
	
	for (i = 1; i <= count; i++)
	{
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < 2; k++)
			{
				cur[j ^ k] += c[i][k] * old[j];
				cur[j ^ k] %= MOD;
			}
		}
		memcpy(old, cur, sizeof(cur));
		memset(cur, 0, sizeof(cur));
	}
	
	ll ans = old[1];
	for (i = 1; i <= m; i++)
	{
		if (var[i].size() == 0)
		{
			ans = ans * 2 % MOD;
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}