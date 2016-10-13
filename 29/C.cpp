#include <cstdio>
#include <map>
#include <vector>

using namespace std;

const int N = 1e5 + 5;

map<int, vector<int> > route;
map<int, bool> visit;
vector<int> ans;

int main()
{
	int n, i, u, v;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		route[u].push_back(v);
		route[v].push_back(u);
	}
	
	map<int, vector<int> >::iterator iter;
	for (iter = route.begin(); iter != route.end(); iter++)
	{
		if (iter->second.size() == 1)
		{
			break;
		}
	}
	u = iter->first;
	
	while (!visit[u])
	{
		visit[u] = true;
		ans.push_back(u);
		vector<int> &vec = route[u];
		for (i = 0; i < vec.size(); i++)
		{
			if (!visit[vec[i]])
			{
				u = vec[i];
				break;
			}
		}
	}
	
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}