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
	int n, i;
	cin >> n;
	
	if (n % 2 == 0)
	{
		cout << n / 2 << endl;
		for (i = 0; i < n / 2; i++)
		{
			cout << 2 << " ";
		}
		cout << endl;
	}
	else
	{
		n -= 3;
		cout << n / 2 + 1 << endl;
		cout << 3 << " ";
		for (i = 0; i < n / 2; i++)
		{
			cout << 2 << " ";
		}
		cout << endl;
	}
	
	return 0;
}