#include<bits/stdc++.h>

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

const int N = 1e5 + 100;

int A[N], B[N], C[N];
map<pii, set<pii, greater<pii> > > mm;
vector<int> ansVec;

int main()
{
	// USE_IOSTREAM;
	int n, t1, t2, t3, a, b, c, ans, i;
	ans = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &t1, &t2, &t3);
		c = max(t1, max(t2, t3));
		if (c == t3)
		{
			b = max(t1, t2);
			a = min(t1, t2);
		}
		else if (c == t2)
		{
			b = max(t1, t3);
			a = min(t1, t3);
		}
		else
		{
			b = max(t2, t3);
			a = min(t2, t3);
		}
		A[i] = a;
		B[i] = b;
		C[i] = c;
		/*
		set<pii, greater<pii> > &vab = mm[mp(a, b)];
		while (vab.size() && vab.begin()->first < c)
		{
			vab.erase(vab.begin());
		}
		if (vab.size() < 2)
		{
			vab.insert(mp(c, i));
		}
		
		set<pii, greater<pii> > &vac = mm[mp(a, c)];
		while (vac.size() && vac.begin()->first < b)
		{
			vac.erase(vac.begin());
		}
		if (vac.size() < 2)
		{
			vac.insert(mp(b, i));
		}*/
		
		set<pii, greater<pii> > &vbc = mm[mp(b, c)];
		while (vbc.size() && vbc.begin()->first < a)
		{
			vbc.erase(vbc.begin());
		}
		if (vbc.size() < 2)
		{
			vbc.insert(mp(a, i));
		}
		
		if (a > ans)
		{
			ans = a;
			ansVec.clear();
			ansVec.push_back(i);
		}
	}
	

	for (i = 1; i <= n; i++)
	{
		a = A[i];
		b = B[i];
		c = C[i];
		
		set<pii, greater<pii> > &vbc = mm[mp(b, c)];
		if (vbc.begin()->second != i)
		{
			if (min(b, a + vbc.begin()->first) > ans)
			{
				ans = min(b, a + vbc.begin()->first);
				ansVec.clear();
				ansVec.push_back(i);
				ansVec.push_back(vbc.begin()->second);
			}
		}
		else if (vbc.size() > 1)
		{
			if (min(b, a + vbc.rbegin()->first) > ans)
			{
				ans = min(b, a + vbc.rbegin()->first);
				ansVec.clear();
				ansVec.push_back(i);
				ansVec.push_back(vbc.rbegin()->second);
			}
		}
	}
	
	
	printf("%d\n", ansVec.size());
	for (auto i : ansVec)
	{
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}