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

bool isPrime(int n)
{
	if (n <= 3)
	{
		return true;
	}
	
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	// USE_IOSTREAM;
	int n, i, ans;
	scanf("%d", &n);
	
	if (isPrime(n))
	{
		ans = 1;
	}
	else if (n % 2 == 0)
	{
		ans = 2;
	}
	else if (isPrime(n - 2))
	{
		ans = 2;
	}
	else
	{
		ans = 3;
	}
	
	
	printf("%d\n", ans);
	return 0;
}