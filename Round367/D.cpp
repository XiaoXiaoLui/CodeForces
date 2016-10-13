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

const int N = 2e5 + 100;

struct Node
{
	Node() : left(0), right(0), value(0), count(0), parent(0)
	{
	}
	int parent;
	int left;
	int right;
	int value;
	int count;
};

struct Tree
{
	Tree() : num(1)
	{
	}
	
	void insert(int x)
	{
		int p, i, next;
		bool goRight;
		for (p = 1, i = 31; i >= 0; i--, p = next)
		{
			if ((x >> i) & 1)
			{
				next = a[p].right;
				goRight = true;
			}
			else
			{
				next = a[p].left;
				goRight = false;
			}
			
			if (next == 0)
			{
				next = ++num;
				a[next].parent = p;
				if (goRight)
				{
					a[p].right = next;
				}
				else
				{
					a[p].left = next;
				}
			}
		}
		a[p].value = x;
		a[p].count++;
	}
	
	void erase(int x)
	{
		int p, i, next, pre;

		for (p = 1, i = 31; i >= 0; i--, p = next)
		{
			if ((x >> i) & 1)
			{
				next = a[p].right;
			}
			else
			{
				next = a[p].left;
			}
		}
		
		a[p].count--;
		while (a[p].count == 0 && a[p].left == 0 && a[p].right == 0)
		{
			pre = a[p].parent;
			if (p == a[pre].left)
			{
				a[pre].left = 0;
			}
			else
			{
				a[pre].right = 0;
			}
			p = pre;
			if (p == 1)
			{
				break;
			}
		}
	}
	
	int query(int x)
	{
		int p, i, next;
		int res = x;
		for (p = 1, i = 31; i >= 0 && p; i--, p = next)
		{
			if (!((x >> i) & 1))
			{
				if (a[p].right)
				{
					next = a[p].right;
				}
				else
				{
					next = a[p].left;
				}
			}
			else
			{
				if (a[p].left)
				{
					next = a[p].left;
				}
				else
				{
					next = a[p].right;
				}	
			}
			
			if (a[next].count > 0)
			{
				res = max(res, a[next].value ^ x);
			}
		}
		
		return res;
	}
	
	Node a[N * 50];
	int num;
} tr;

vector<int> ans;
char type[N];
int x[N];

inline void nextLine()
{
	while (getchar() != '\n');
}

int main()
{
	int n, i;
	
	scanf("%d", &n);
	nextLine();
	
	for (i = 0; i < n; i++)
	{
		scanf("%c%d", &type[i], &x[i]);
		nextLine();
	}
	for (i = 0; i < n; i++)
	{
		if (type[i] == '+')
		{
			tr.insert(x[i]);
		}
		else if (type[i] == '-')
		{
			tr.erase(x[i]);
		}
		else
		{
			ans.push_back(tr.query(x[i]));
		}
	}
	
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d\n", ans[i]);
	}
	
	printf("\n");
	return 0;
}