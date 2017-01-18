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



int main()
{
	USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
	set<string> wordSet;
    string str;
    
    int n, m, i;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> str;
        wordSet.insert(str);
    }
    
    int commonCnt = 0;
    for (i = 1; i <= m; i++)
    {
        cin >> str;
        if (wordSet.count(str) > 0)
        {
            commonCnt++;
        }
    }
    
    int word1 = n - commonCnt + (commonCnt + 1) / 2;
    int word2 = m - commonCnt + (commonCnt) / 2;
    
    
    if (word1 > word2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
	return 0;
}