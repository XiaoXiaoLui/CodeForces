// include stdc++.h slows down compilation much.
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

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

const int N = 1e4 + 100;
int parent[N];

int find(int u)
{
    if (parent[u] == u)
    {
        return u;
    }
    
    return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    int pu = find(u);
    int pv = find(v);
    parent[pu] = pv;
}

int main()
{
	USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
    int i, u, v, n;
    cin >> n;
    
    for (i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (i = 1; i <= n; i++)
    {
        cin >> u;
        merge(i, u);
    }
    
    int ans = 0;
    for (i = 1; i <= n; i++)
    {
        if (parent[i] == i)
        {
            ans++;
        }
    }
    
    cout << ans << endl;
	
	return 0;
}