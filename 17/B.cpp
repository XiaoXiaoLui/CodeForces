#include <iostream>
#include <set>

using namespace std;

struct App
{
	int sub;
	int super;
	int cost;
	
	bool operator < (const App &other) const
	{
		return cost < other.cost || (cost == other.cost && (sub < other.sub || (sub == other.sub && super < other.super)));
	}
};

const int M = 10001;
const int N = 1001;

set<App> appSet;
set<App> a[N];


int main()
{
	int n, m, ans, q, i, j;
	App app;
	
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> q;
	}
	
	cin >> m;
	
	for (i = 0; i < m; i++)
	{
		cin >> app.super >> app.sub >> app.cost;
		a[app.sub].insert(app);
		appSet.insert(app);
	}
	
	set<App>::iterator iter;
	ans = 0;
	for (i = 1; i < n && !appSet.empty(); i++)
	{
		iter = appSet.begin();
		ans += iter->cost;
		
		j = iter->sub;
		for (iter = a[j].begin(); iter != a[j].end(); iter++)
		{
			appSet.erase(*iter);
		}
	}
	
	if (i == n)
	{
		cout << ans << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	
	
	
	
	return 0;
}