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

vector<pii> ans;

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	int n, k, u, v, i, j;
    cin >> n >> k;
    
    if (k == 1 || k > 3 || n <= 3 || (n == 4 && k == 2))
    {
        printf("-1\n");
        return 0;
    }
    
    if (k == 2)
    {
        int num = (n - 2) / 2;
        u = 2*num + 1;
        v = 2*num + 2;
        for (i = 1; i <= num; i++)
        {
            ans.push_back({i, i + num});
            ans.push_back({u, i});
            ans.push_back({i + num, v});
        }
        
        if (n & 1)
        {
            ans.push_back({n, u});
            ans.push_back({n, v});
        }
    }
    else
    {
        ans.push_back({1, 2});
        ans.push_back({2, 3});
        for (i = 4; i <= n; i++)
        {
            ans.push_back({3, i});
        }
    }
    
    printf("%d\n", ans.size());
    for (auto e : ans)
    {
        printf("%d %d\n", e.first, e.second);
    }
	return 0;
}