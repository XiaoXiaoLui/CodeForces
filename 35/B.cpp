#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
#define mp make_pair<int, int>

struct Query
{
	int type;
	int x;
	int y;
	string name;
};


const int N = 2005;
Query q[N];
map<pair<int, int>, string> a;

int main()
{
	int n, m, num, type, x, y, i, j;
	char name[20];
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	
	fscanf(in, "%d%d%d", &n, &m, &num);
	for (i = 0; i < num; i++)
	{
		fscanf(in, "%d", &type);
		if (type == 1)
		{
			fscanf(in, "%d%d", &x, &y);
		}
		fscanf(in, "%s", name);
		q[i].type = type;
		q[i].x = x;
		q[i].y = y;
		q[i].name = name;
	}
	
	for (i = 0; i < num; i++)
	{
		if (q[i].type == 1)
		{
			x = q[i].x;
			y = q[i].y;
			while (a.count(mp(x, y)) > 0)
			{
				y++;
				if (y > m)
				{
					x++;
					y = 1;
				}
				if (x > n)
				{
					break;
				}
			}
			if (x <= n)
			{
				a[mp(x, y)] = q[i].name;
			}
		}
		else
		{
			bool find = false;
			map<pair<int, int>, string>::iterator iter;
			for (iter = a.begin(); iter != a.end(); iter++)
			{
				if (iter->second == q[i].name)
				{
						find = true;
						break;
				}
			}
			if (!find)
			{
				x = -1;
				y = -1;
			}
			else
			{
				x = iter->first.first;
				y = iter->first.second;
				a.erase(iter);
			}
			fprintf(out, "%d %d\n", x, y);
		}
	}
	
	return 0;
}