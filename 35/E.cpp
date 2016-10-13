#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int N = 1e5 + 5;



struct Point
{
	int x;
	int y;
	
	Point(){}
	Point(int a, int b) : x(a), y(b)
	{
	}
	
	bool operator == (const Point &other) const
	{
		return x == other.x && y == other.y;
	}
};

struct Building
{
	int l;
	int r;
	int h;
};

struct Line
{
	Line(){}
	Line(int a, int b, int c) : x(a), y(b), type(c)
	{
	}
	int x;
	int y;
	int type;
	
	bool operator < (const Line &other) const
	{
		return x < other.x || (x == other.x && (type > other.type || type == other.type && y > other.y));
	}
};

struct Cmp
{
	bool operator () (const Line &a, const Line &b) const
	{
		return a.y < b.y;
	}
};

vector<Point> ans;
Building a[N];
Line b[2*N];
int x[2*N];

int main()
{
	int n, i, m;
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	
	if (!in || !out)
	{
		printf("ERROR OPEN FILE\n");
		return 1;
	}
	
	fscanf(in, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%d%d%d", &a[i].h, &a[i].l, &a[i].r);
		b[2*i] = Line(a[i].l, a[i].h, 0);
		b[2*i + 1] = Line(a[i].r, a[i].h, 1);
	}
	n *= 2;
	
	sort(b, b + n);
	map<int, int> hMap;
	multiset<Line, Cmp> S;
	multiset<Line, Cmp>::iterator iter;
	int maxH = 0;
	
	for (i = 0; i < n; i++)
	{
		if (b[i].type == 0)
		{
			S.insert(b[i]);
			hMap[b[i].x] = S.rbegin()->y;
		}
		else
		{
			iter = S.find(b[i]);
			S.erase(iter);
			hMap[b[i].x] = S.empty() ? 0 : S.rbegin()->y;
		}
	}
	
	m = 0;
	x[m++] = b[0].x;
	for (i = 1; i < n; i++)
	{
		if (b[i].x != b[i - 1].x)
		{
			x[m++] = b[i].x;
		}
	}
	ans.push_back(Point(x[0], 0));
	
	
	Point p1, p2;
	for (i = 0; i < m - 1; i++)
	{

		maxH = hMap[x[i]];
		p1 = Point(x[i], maxH);
		p2 = Point(x[i + 1], maxH);
		if (p1.y == ans.back().y)
		{
			ans.pop_back();
			ans.push_back(p2);
		}
		else
		{
			ans.push_back(p1);
			ans.push_back(p2);		
		}
				
		
	}
	ans.push_back(Point(ans.back().x, 0));
	
	fprintf(out, "%d\n", ans.size());
	for (i = 0; i < ans.size(); i++)
	{
		fprintf(out, "%d %d\n", ans[i].x, ans[i].y);
	}
	fclose(in);
	fclose(out);
	
	return 0;
}