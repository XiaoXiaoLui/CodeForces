#include <cstdio>
#include <queue>

using namespace std;

const int N = 505;
struct State
{
	State(){}
	State(int a, int b, int c)
	{
		p1 = a;
		p2 = b;
		turn = c;
	}
	int p1;
	int p2;
	int turn;
};


int dist[N][N][2];
State pre[N][N][2];
vector<int> graph[N];

int main()
{
	int n, m, i, u, v;
	scanf("%d%d", &n, &m);
	
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	queue<State> Q;
	State init(1, n, 0);
	dist[1][n][0] = 0;
	Q.push(init);
	State cur, tmp;
	while (!Q.empty())
	{
		cur = Q.front();
		Q.pop();
		int p1, p2, next;
		p1 = cur.p1;
		p2 = cur.p2;
		if (cur.turn == 1)
		{
			for (i = 0; i < graph[p2].size(); i++)
			{
				next = graph[p2][i];
				if (next == p1 || dist[p1][next][0])
				{
					continue;
				}
				dist[p1][next][0] = dist[p1][p2][1] + 1;
				pre[p1][next][0] = State(p1, p2, 1);
				Q.push(State(p1, next, 0));
			}
		}
		else
		{
			for (i = 0; i < graph[p1].size(); i++)
			{
				next = graph[p1][i];
				if (dist[next][p2][1])
				{
					continue;
				}
				dist[next][p2][1] = dist[p1][p2][0] + 1;
				pre[next][p2][1] = State(p1, p2, 0);
				Q.push(State(next, p2, 1));
			}
		}
	}

	vector<int> ans1;
	vector<int> ans2;
	if (dist[n][1][0])
	{
		tmp = State(n, 1, 0);
		int num = dist[n][1][0] / 2 + 1;
		for (i = 0; i < num; i++)
		{
			ans1.push_back(tmp.p1);
			ans2.push_back(tmp.p2);
			tmp = pre[tmp.p1][tmp.p2][tmp.turn];
			tmp = pre[tmp.p1][tmp.p2][tmp.turn];
		}
		
		printf("%d\n", num - 1);
		for (i = ans1.size() - 1; i >= 0; i--)
		{
			printf("%d ", ans1[i]);
		}
		printf("\n");
		for (i = ans2.size() - 1; i >= 0; i--)
		{
			printf("%d ", ans2[i]);
		}
		printf("\n");
		
	}
	else
	{
		printf("-1\n");
	}
	
	return 0;
}