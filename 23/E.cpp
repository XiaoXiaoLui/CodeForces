#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

const int N = 705;

class BigInt
{
public:
	BigInt(int n = 0)
	{
		memset(array, 0, sizeof(array));
		len = 1; 
		array[0] = n;
	}
	
	BigInt operator +(const BigInt &other) const
	{
		BigInt c;
		c.len = max(len, other.len);
		int end = min(len, other.len);
		int r = 0;
		int i;
		for (i = 0; i < end; i++)
		{
			c.array[i] = array[i] + other.array[i] + r;
			r = c.array[i] / M;
			c.array[i] %= M;
		}
		
		if (end < len)
		{
			for (; i < c.len; i++)
			{
				c.array[i] = array[i] + r;
				r = c.array[i] / M;
				c.array[i] %= M;
			}
		}
		else if (end < other.len)
		{
			for (; i < c.len; i++)
			{
				c.array[i] = other.array[i] + r;
				r = c.array[i] / M;
				c.array[i] %= M;
			}
		}
		if (r)
		{
			c.array[c.len++] = r;
		}
		
		return c;
	}
	
	BigInt operator *(const BigInt &other) const
	{
		BigInt c;
		
		int i, j;
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < other.len; j++)
			{
				c.array[i + j] += array[i] * other.array[j];
			}
		}
		
		c.len = other.len + len;
		int r = 0;
		for (i = 0; i < c.len; i++)
		{
			c.array[i] += r;
			r = c.array[i] / M;
			c.array[i] %= M;
		}
		if (!c.array[c.len - 1] && c.len > 1)
		{
			c.len--;
		}
		
		return c;
	}
	
	bool operator < (const BigInt &other) const
	{
		if (len < other.len)
		{
			return true;
		}
		else if (len > other.len)
		{
			return false;
		}
		
		for (int i = len - 1; i >= 0; i--)
		{
			if (array[i] != other.array[i])
			{
				return array[i] < other.array[i];
			}
		}
		
		return false;
	}
	
	void print()
	{
		printf("%d", array[len - 1]);
		for (int i = len - 2; i >= 0; i--)
		{
			printf("%04d", array[i]);
		}
		printf("\n");
	}

private:
	const static int M = 10000;
	int array[30];
	int len;
};

BigInt bigIntMax(const BigInt &a, const BigInt &b)
{
	return (a < b) ? b : a;
}


BigInt dp[N];
BigInt f[N][N];
BigInt g[N][N];
vector<int> graph[N];
int son[N];
bool visit[N];

void dfs(int u)
{
	visit[u] = true;
	
	g[u][1] = BigInt(1);
	f[u][1] = BigInt(1);
	int count = 1;
	
	int i, j, v;
	for (int index = 0; index < graph[u].size(); index++)
	{
		v = graph[u][index];
		if (visit[v])
		{
			continue;
		}
		dfs(v);
		
		for (i = 1; i <= count; i++)
		{
			f[u][i] = g[u][i] * dp[v];
		}
		
		for (i = 1; i <= count; i++)
		{
			for (j = 1; j <= son[v]; j++)
			{
				f[u][i + j] = bigIntMax(f[u][i + j], g[u][i] * f[v][j]);
			}
		}
		
		count += son[v];
		for (i = 1; i <= count; i++)
		{
			g[u][i] = f[u][i];
		}
	}
	
	for (i = 1; i <= count; i++)
	{
		dp[u] = bigIntMax(dp[u], f[u][i] * BigInt(i));
	}
	
	son[u] = count;
}

int main()
{
	int n, i, u, v;
	
	scanf("%d", &n);
	
	for (i = 1; i <= n - 1; i++)
	{
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1);
	
	
	dp[1].print();
	return 0;
}