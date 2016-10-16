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

#define USE_IOSTREAM \
	ios_base::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 1e6 + 10;
const int M = 1e5 + 100;

//string name[M];
vector<string> name;
int match[N];
string seq;

struct AhoTree
{
	AhoTree() : num(1)
	{
		// memset all to 0
		// since ahoTree is global, this has been done automicly
	}
	
	void add(int index, const string &str)
	{
		int u, v, i, c;
		for (i = 0, u = 0; i < str.length(); i++)
		{
			c = str[i] - 'a';
			if (!tr[u][c])
			{
				tr[u][c] = num++;
			}
			u = tr[u][c];
		}
		e[u] = index;
	}
	
	void build()
	{
		front = rear = 0;
		q[rear++] = 0;
		
		int u, v, i;
		
		while (front != rear)
		{
			u = q[front];
			front++;

			for (i = 0; i < 26; i++)
			{
				v = tr[u][i];
				if (v)
				{
					if (u)
					{
						f[v] = tr[f[u]][i];
					}
					q[rear++] = v;
				}
				else
				{
					tr[u][i] = tr[f[u]][i];
				}
			}
		}
	}
	
	int calMatchTable(const string &str)
	{
		int c, i, u;
		for (i = 0, u = 0; i < str.size(); i++)
		{
			c = str[i] - 'a';
			u = tr[u][c];
			match[i] = e[u];
		}
		
		return u;
	}
	
	int next(int cur, char c)
	{
		return tr[cur][c - 'a'];
	}
	
	int e[2*N];
	int tr[2*N][28];
	//int au[N][28];
	int f[2*N];
	
	int q[2*N];
	int front, rear;
	int num;
} ahoTree;

bool used[M];
vector<int> cash;

int main()
{
	USE_IOSTREAM;
	
	int n, w, m, i, j, offset, cur;
	string tmp;
	cin >> n >> w;
	cin >> seq;
	
	cin >> m;
	name.push_back("");
	for (i = 1; i <= m; i++)
	{
		cin >> tmp;
		name.push_back(tmp);
		ahoTree.add(i, name[i]);
	}
	
	ahoTree.build();
	cur = ahoTree.calMatchTable(seq);
	
	bool ok = false;
	for (offset = 0; offset < w && !ok; offset++)
	{
		ok = true;
		if (offset != 0)
		{
			cur = ahoTree.next(cur, seq[offset - 1]);
			i = ahoTree.e[cur];
			if (i == 0)
			{
				ok = false;
			}
			used[i] = true;
			cash.push_back(i);
		}
		
		for (j = offset + w - 1; j < seq.size() && ok; j += w)
		{
			if (match[j] == 0 || used[match[j]])
			{
				ok = false;
				break;
			}
			used[match[j]] = true;
			cash.push_back(match[j]);
		}
		
		if (ok)
		{
			break;
		}
		
		for (i = 0; i < cash.size(); i++)
		{
			used[cash[i]] = false;
		}
		cash.clear();
	}
	
	if (ok)
	{
		printf("YES\n");
		for (i = 0; i < cash.size(); i++)
		{
			printf("%d ", cash[i]);
		}
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}
	
	return 0;
}