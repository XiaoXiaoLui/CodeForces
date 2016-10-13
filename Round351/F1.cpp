#include <iostream>
#include <set>


using namespace std;

typedef long long ll;

const int N = 100004;


ll t[N];
int f[N];
set<int> g[N];
multiset<ll> sortIncome;
ll income[N];
//int minIndex = 1, maxIndex = 1;
int n;


ll mainIncome(ll t, ll k)
{
	return t - (k + 1) * (t / (k + 2));
}

ll subIncome(ll t, ll k)
{
	return t / (k + 2);
}

void updateIncome(int i, ll value)
{
	sortIncome.erase(income[i]);
	income[i] = value;
	sortIncome.insert(income[i]);
}

void debugCheck(int number)
{
	ll s = 0;
	set<int>::iterator iter;
	
	bool hasStart = false;
	for (int i = 1; i <= n; i++)
	{
		s = mainIncome(t[i], g[i].size());
		
		s += subIncome(t[f[i]], g[f[i]].size());
		
		for (iter = g[i].begin(); iter != g[i].end(); iter++)
		{
			s += subIncome(t[*iter], g[*iter].size());
		}
		
		if (income[i] != s)
		{
			if (!hasStart)
			{
				cout << endl;
				cout << "FailCheck: " << number << endl;
			}
			
			cout << i << ":" << s << ", " << income[i] << endl;
		}
	}
	
	if (hasStart)
	{
		cout << endl;
	}
}


int main()
{
	int  m, i, j;
	
	cin >> n >> m;
	
	for (i = 1; i <= n; i++)
	{
		cin >> t[i];
	}
	
	for (i = 1; i <= n; i++)
	{
		cin >> f[i];
		g[f[i]].insert(i);
		sortIncome.insert(0);
	}
	
	ll s = 0;
	set<int>::iterator iter;
	for (i = 1; i <= n; i++)
	{
		s = mainIncome(t[i], g[i].size());
		
		s += subIncome(t[f[i]], g[f[i]].size());
		
		for (iter = g[i].begin(); iter != g[i].end(); iter++)
		{
			s += subIncome(t[*iter], g[*iter].size());
		}
		
		updateIncome(i, s);
		
	}
	
	int type, a, b, c, preK, curK;
	for (i = 1; i <= m; i++)
	{
		cin >> type;
		if (type == 1)
		{
			cin >> a >> b;
			
			c = f[a];
			

			// for c
			g[c].erase(a);
			curK = g[c].size();
			preK = curK + 1;
			updateIncome(c, income[c] - mainIncome(t[c], preK) + mainIncome(t[c], curK) - subIncome(t[a], g[a].size()));
			
			for (iter = g[c].begin(); iter != g[c].end(); iter++)
			{
				updateIncome(*iter, income[*iter] - subIncome(t[c], preK) + subIncome(t[c], curK));
			}
			
			updateIncome(f[c], income[f[c]] - subIncome(t[c], preK) + subIncome(t[c], curK));
			
			// for b
			preK = g[b].size();
			curK = preK + 1;
			updateIncome(b, income[b] - mainIncome(t[b], preK) + mainIncome(t[b],curK) + subIncome(t[a], g[a].size()));
			
			for (iter = g[b].begin(); iter != g[b].end(); iter++)
			{
				updateIncome(*iter, income[*iter] - subIncome(t[b], preK) + subIncome(t[b], curK));
			}
			
			
			updateIncome(f[b], income[f[b]] - subIncome(t[b], preK) + subIncome(t[b], curK));
			g[b].insert(a);
			f[a] = b;
			
			// for a
			updateIncome(a, income[a] - subIncome(t[c], g[c].size() + 1) + subIncome(t[b], g[b].size()));
			
			
			//debugCheck(i);
					
		}
		else if (type == 2)
		{
			cin >> a;
			cout << income[a] << endl;
		}
		else
		{
			cout << *(sortIncome.begin()) << " " << *(sortIncome.rbegin()) << endl;
		}
	}
	
	
	
	return 0;
}