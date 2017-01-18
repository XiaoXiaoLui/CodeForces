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
#include <bitset>

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

const int N = 1e6 + 100;

int a[N];
int cnt[N];
bool visit[N];

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
    
    int n, k, i, j, maxAns, minAns;
    scanf("%d%d", &n, &k);
    
	for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for (i = 1; i <= n; i++)
    {
        if (visit[i])
        {
            continue;
        }
        
        int curLen = 0;
        for (j = i; !visit[j]; j = a[j])
        {
            visit[j] = true;
            curLen++;
        }
        cnt[curLen]++;
    }
    
    maxAns = 0;
    int tmp = k;
    for (i = 2; i <= n && tmp; i++)
    {
        if (!cnt[i])
        {
            continue;
        }
        
        maxAns += min(2*tmp, i / 2 * 2 * cnt[i]);
        tmp -= min(tmp, i / 2 * cnt[i]);
    }
    maxAns += tmp;
    maxAns = min(maxAns, n);
    
	for (i = 2; i <= k; i++)
    {
        if (cnt[i] <= 2)
        {
            continue;
        }
        
        if (cnt[i] & 1)
        {
            if (2 * i <= k)
            {
                cnt[2 * i] += cnt[i] / 2;
            }
            cnt[i] = 1;
        }
        else
        {
            if (2 * i <= k)
            {
                cnt[2 * i] += (cnt[i] - 2) / 2;
            }
            cnt[i] = 2;
        }
    }
    
    minAns = k;
    bitset<N> curDp;
    curDp[0] = true;
    
    int loop = 0;
    for (i = 2; i <= k; i++)
    {
        if (!cnt[i])
        {
            continue;
        }
  
      
        if (cnt[i] == 1)
        {
            curDp |= curDp << i;
        }
        else // == 2
        {
            curDp |= (curDp << i) | (curDp << (i + i));
        }
    }
    
    if (!curDp[k])
    {
        minAns++;
    }
    
    if (k == 0)
    {
        maxAns = minAns = 0;
    }
    
    printf("%d %d", minAns, maxAns);
	return 0;
}