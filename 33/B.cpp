#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;
const int MAX = 1e7;

char s1[N];
char s2[N];
char ans[N];
int cost[130][130];
int w[130][130];
char to[130][130];

int main()
{
	int len, i, n, v, j, k, sum;
	char c1, c2;
	bool ok = true;
	scanf("%s%s%d", s1, s2, &n);
	
	do
	{
		scanf("%c", &c1);
	} while (c1 != '\n');
	
	
	for (i = 0; i < 130; i++)
	{
		fill(cost[i], cost[i] + 130, MAX);
		fill(w[i], w[i] + 130, MAX);
	}
	for (i = 'a'; i <= 'z'; i++)
	{
		cost[i][i] = 0;
		w[i][i] = 0;
		to[i][i] = (char)i;
	}
	
	for (i = 1; i <= n; i++)
	{
		scanf("%c%*c%c%d", &c1, &c2, &v);
		w[c1][c2] = min(w[c1][c2], v);
		do
		{
			scanf("%c", &c1);
		} while (c1 != '\n');
	}
	
	len = strlen(s1);
	if (len != strlen(s2))
	{
		ok = false;
	}
	
	// shortest path, floyed
	for (k = 'a'; k <= 'z'; k++)
	{
		for (i = 'a'; i <= 'z'; i++)
		{
			for (j = 'a'; j <= 'z'; j++)
			{
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
			}
		}
	}
	
	// min cost
	
	for (i = 'a'; i <= 'z'; i++)
	{
		for (j = 'a'; j <= 'z'; j++)
		{
			for (k = 'a'; k <= 'z'; k++)
			{
				if (w[i][k] + w[j][k] < cost[i][j])
				{
					cost[i][j] = w[i][k] + w[j][k];
					to[i][j] = (char)k;
				}
			}
		}
	}
	
	
	if (ok)
	{
		sum = 0;
		for (i = 0; i < len; i++)
		{
			if (s1[i] == s2[i])
			{
				ans[i] = s1[i];
			}
			else if (cost[s1[i]][s2[i]] == MAX && cost[s2[i]][s1[i]] == MAX)
			{
				ok = false;
				break;
			}
			else if (cost[s1[i]][s2[i]] <= cost[s2[i]][s1[i]])
			{
				sum += cost[s1[i]][s2[i]];
				ans[i] = to[s1[i]][s2[i]];
			}
			else
			{
				sum += cost[s2[i]][s1[i]];
				ans[i] = to[s2[i]][s1[i]];
			}
		}
		ans[len] = '\0';
	}
	
	
	if (ok)
	{
		printf("%d\n%s\n", sum, ans);
	}
	else
	{
		printf("-1\n");
	}
	
	return 0;
}