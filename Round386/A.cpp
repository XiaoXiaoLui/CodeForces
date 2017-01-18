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



int main()
{
	USE_IOSTREAM;
	int a, b, c;
	cin >> a >> b >> c;
	
	cout << (min(a, min(b / 2, c / 4))) * 7 << endl;
	
	return 0;
}