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
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << n << " " << n + 1 << " " << n * (n + 1) << endl;
	}
	
	return 0;
}