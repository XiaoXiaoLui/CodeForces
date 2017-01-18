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

int X[3], Y[3];

int main()
{
	USE_IOSTREAM;
	int i, x, y;
	for (i = 0; i < 3; i++)
	{
		cin >> X[i] >> Y[i];
	}
	
	cout << 3 << endl;
	for (i = 0; i < 3; i++)
	{
		x = X[(i + 1) % 3] + X[(i + 2) % 3] - X[i];
		y = Y[(i + 1) % 3] + Y[(i + 2) % 3] - Y[i];
		
		cout << x << " " << y << endl;
	}
	
	return 0;
}