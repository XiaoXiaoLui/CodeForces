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

const int N = 1050;
const int M = 1e4 + 50;

struct Node
{
	int left;
	int right;
	int up;
	int down;
	
	int e;
};

struct Query
{
	int a;
	int b;
	int c;
	int d;
	int h;
	int w;
};

Node node[N*N];
Query q[M];
//int a[M], b[M], c[M], d[M], h[M], w[M];

int main()
{
	int n, m, qNum, i, j, k, v, a, b, c, d, h, w, s1, s2, p1, p2, tmp;
	scanf("%d%d%d", &n, &m, &qNum);
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &v);
			node[i * (m + 2) + j].e = v;
		}
	}
	
	for (i = 0; i < (n + 2) * (m + 2); i++)
	{
		node[i].left = i - 1;
		node[i].right = i + 1;
		node[i].up = i - (m + 2);
		node[i].down = i + (m + 2);
	}
	
	
	for (i = 0; i < qNum; i++)
	{
		scanf("%d%d%d%d%d%d", &q[i].a, &q[i].b, &q[i].c, &q[i].d, &q[i].h, &q[i].w);
	}
	
	for (k = 0; k < qNum; k++)
	{
		a = q[k].a;
		b = q[k].b;
		c = q[k].c;
		d = q[k].d;
		h = q[k].h;
		w = q[k].w;
		
		for (i = 1, s1 = node[1].down; i < a; i++, s1 = node[s1].down);
		for (j = 1; j < b; j++, s1 = node[s1].right);
		
		for (i = 1, s2 = node[1].down; i < c; i++, s2 = node[s2].down);
		for (j = 1; j < d; j++, s2 = node[s2].right);
		
		// left
		for (i = 1, p1 = s1, p2 = s2; i <= h; i++, p1 = node[p1].down, p2 = node[p2].down)
		{
			tmp = node[p1].left;
			node[p1].left = node[p2].left;
			node[node[p1].left].right = p1;
			
			node[p2].left = tmp;
			node[tmp].right = p2;
		}
		
		// up
		for (j = 1, p1 = s1, p2 = s2; j <= w; j++, p1 = node[p1].right, p2 = node[p2].right)
		{
			tmp = node[p1].up;
			node[p1].up = node[p2].up;
			node[node[p2].up].down = p1;
			
			node[p2].up = tmp;
			node[tmp].down = p2;
		}
		
		for (i = 1; i < h; i++, s1 = node[s1].down, s2 = node[s2].down);
		for (j = 1; j < w; j++, s1 = node[s1].right, s2 = node[s2].right);

		// right
		for (i = h, p1 = s1, p2 = s2; i >= 1; i--, p1 = node[p1].up, p2 = node[p2].up)
		{
			tmp = node[p1].right;
			node[p1].right = node[p2].right;
			node[node[p1].right].left = p1;
			
			node[p2].right = tmp;
			node[tmp].left = p2;
		}
		
		// down
		for (j = w, p1 = s1, p2 = s2; j >= 1; j--, p1 = node[p1].left, p2 = node[p2].left)
		{
			tmp = node[p1].down;
			node[p1].down = node[p2].down;
			node[node[p1].down].up = p1;
			
			node[p2].down = tmp;
			node[tmp].up = p2;
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		p1 = node[i * (m + 2)].right;
		for (j = 1; j <= m; j++, p1 = node[p1].right)
		{
			printf("%d ", node[p1].e);
		}
		printf("\n");
	}
	
	return 0;
}