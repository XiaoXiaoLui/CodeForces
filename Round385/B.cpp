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


const int N = 1005;
int M;
int reply[22][N];
int ans[N];
int n;

void ask(vector<int> &a)
{
	if (a.empty())
	{
		return;
	}
	printf("%d\n", a.size());
	for (auto num : a)
	{
		printf("%d ", num);
	}
	printf("\n");
	fflush(stdout);
}

void getResult(int i)
{
	int num;
	for (int k = 1; k <= n; k++)
	{
		scanf("%d", &num);
		reply[i][k] = num;
	}
}

void printResult()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		ans[i] = 2e9;
		for (j = 0; j < M; j++)
		{
			if ((i >> j) & 1)
			{
				ans[i] = min(ans[i], reply[2*j][i]);
			}
			else
			{
				ans[i] = min(ans[i], reply[2*j + 1][i]);
			}
		}
	}
	
	printf("-1\n");
	for (i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	fflush(stdout);
}

int main()
{
	// USE_IOSTREAM;
	int i, j;
	scanf("%d", &n);
	vector<int> vec;
	M = 0;
	int tmp = n;
	while (tmp)
	{
		tmp /= 2;
		M++;
	}
	
	for (i = 0; i < M; i++)
	{
		vec.clear();
		for (j = 1; j <= n; j++)
		{
			if (!((j >> i) & 1))
			{
				vec.push_back(j);
			}
		}
		ask(vec);
		getResult(2*i);
		
		vec.clear();
		for (j = 1; j <= n; j++)
		{
			if ((j >> i) & 1)
			{
				vec.push_back(j);
			}
		}
		ask(vec);
		getResult(2*i + 1);
	}
	
	printResult();
	
	return 0;
}