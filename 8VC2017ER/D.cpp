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

const int N = 1 << 20;

ll tr[2*N];


ll query(int left, int right)
{
	int l, r;
    ll res;
	res = 0;
	for (l = left + N, r = right + N + 1; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
		{
			res += tr[l++];
		}
		if (r & 1)
		{
			res += tr[--r];
		}
	}
	return res;
}

void update(int pos)
{
	int id = (pos + N);
	tr[id]++;
	
	for (id >>= 1; id >= 1; id >>= 1)
	{
		tr[id] = tr[2*id] + tr[2*id + 1];
	}
}

ll solve(int pos, int n, int k)
{
    int nextPos = (pos + k) % n;
    
    ll res = 0;
    if (nextPos > pos)
    {
        res = query(pos + 1, nextPos) + 1;
    }
    else
    {
        res = query(pos + 1, n - 1) + query(0, nextPos) + 1;
    }
    
    return res;
}

vector<ll> ans;

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	int n, k;
    cin >> n >> k;
    
    if (2*k > n)
    {
        k = n - k;
    }
    int i, pos;
    ll curSum = 1;
 
    for (i = 1, pos = 0; i <= n; i++)
    {
        ll res = solve(pos, n, k);
        curSum += res;
        ans.push_back(curSum);
        
        update(pos);
        pos = (pos + k) % n;
        update(pos);
    }
    
    ans[n - 1]--;
    for (i = 0; i < n; i++)
    {
        printf("%lld ", ans[i]);
    }
    printf("\n");
	
	return 0;
}