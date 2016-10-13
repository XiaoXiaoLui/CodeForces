#include <iostream>
#include <set>

using namespace std;

const int N = 100003;

ll t[N];
int f[N];
set<int> g[N];
multiset<ll> h[N];
multiset<ll> minmaxIncomeSet;
ll partIncome[N];


ll mainIncome(ll t, ll k)
{
	return t - (k + 1) * (t / (k + 2));
}

ll subIncome(ll t, ll k)
{
	return t / (k + 2);
}

ll totalIncome(int i)
{
	ll s = partIncome[i];
	
	s += subIncome(t[f[i]], h[f[i]].size());
	
	return s;
}

ll totalIncome(int f, ll part)
{
	ll s = part;
	s += subIncome(t[f], h[f].size());
	
	return s;
}

void updateIncome(int j, ll value)
{
	int i = f[j];
	multiset<ll>::iterator iter;
	if (h[i].empty())
	{
		partIncome[i] = value;
		h[i].insert(value);
		minmaxIncomeSet.insert(value + subIncome();
	}
	else if (*h[i].begin() == partIncome[i])
	{
		h[i].erase(h[i].begin());
		if (h[i].size() > 1)
		{
			minmaxIncomeSet.erase(partIncome[i])
		}
	}
	else if (*h[i].rbegin() == partIncome[i])
	{
		h[i].erase(h[i].rbegin();
	}
	

	
}

int main()
{
	int n, m, i;
	
	cin >> n >> m;
	
	for (i = 1; i <= n; i++)
	{
		cin >> t[i];
	}
	
	for (i = 1; i <= n; i++)
	{
		cin >> f[i];
		g[f[i]].insert(i);
	}
	
	set<int>::iterator iter;
	ll s;
	for (i = 1; i <= n; i++)
	{
		s = mainIncome(t[i], g[i].size());
		for (iter = g[i].begin(); iter != g[i].end(); iter++)
		{
			s += subIncome(*iter, g[*iter].size());
		}
		
		partIncome[i] = s;
		h[f[i]].insert(s);
	}
	
	for (i = 1; i <= n; i++)
	{
		if (h[i].size() == 1)
		{
			minmaxIncomeSet.insert(totalIncome(i, *h[i].begin()));
		}
		else if (h[i].size() > 1)
		{
			minmaxIncomeSet.insert(totalIncome(i, *h[i].begin()));
			minmaxIncomeSet.insert(totalIncome(i, *h[i].rbegin()));
		}
	}
	
	
	int type;
	int a, b, c, d, e;
	ll newPartIncomeC, newPartIncomeB, newPartIncomeD, newPartIncomeE;
	for (i = 1; i <= m; i++)
	{
		cin >> type;
		
		if (type == 1)
		{
			cin >> a >> b;
			c = f[a];
			d = f[c];
			e = f[b];
			
			// for c
			if (*h[c].begin() == partIncome[a])
			{
				minmaxIncomeSet.erase(totalIncome(a));
				g[c].erase(a);
				h[c].erase(h[c].begin());
				if (h[c].size > 1)
				{
					minmaxIncomeSet.insert(totalIncome(c, *h[c].begin()));
				}
			}
			else if (*h[c].rbegin() ==  partIncome[a])
			{
				minmaxIncomeSet.erase(totalIncome(a));
				g[c].erase(a);
				h[c].erase(h[c].rbegin());
				if (h[c].size > 1)
				{
					minmaxIncomeSet.insert(totalIncome(c, *h[c].rbegin()));
				}
			}
			else
			{
				g[c].erase(a);
				h[c].erase(partIncome[a]);
			}
			newPartIncomeC = partIncome[c] - mainIncome(t[c], g[c].size() + 1) + mainIncome(t[c], g[c].size()) - subIncome(t[a], g[a].size());
			
			
			// for d
			newPartIncomeD = partIncome[d] - subIncome(t[c], g[c].size() + 1) + subIncome(t[c], g[c].size());
			if (*h[d].begin() == partIncome[c])
			{
			}
			else if (*h[d].rbegin() == partIncome[c])
			{
			}
			
			// for b
			
			// for e
			
			// for a
		}
		else if (type == 2)
		{
			cin >> a;
			cout << totalIncome(a) << endl;
		}
		else 
		{
			cout << *minmaxIncomeSet.begin() << " " << *minmaxIncomeSet.rbegin() << endl;
		}
	}
	
	
	return 0;
}