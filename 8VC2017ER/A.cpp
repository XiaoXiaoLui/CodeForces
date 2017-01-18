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

const int N = 1e6 + 100;
bool isPrime[N];

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
    
    int i, j, n, m;
    memset(isPrime, 1, sizeof(isPrime));
    
    for (i = 2; i < N; i++)
    {
        for (j = i + i; j < N; j += i)
        {
            isPrime[j] = false;
        }
    }
    
    cin >> n;
    for (m = 1; m <= 1000; m++)
    {
        if (!isPrime[n*m + 1])
        {
            break;
        }
    }
    cout << m << endl;
	
	
	return 0;
}