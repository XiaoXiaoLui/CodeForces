#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

#define N 36

ll d[N][N];

ll dfs(int n, int h)
{
	if (h < 0) 
	{
		h = 0;
	}
	
	if (d[n][h] != -1)
	{
		return d[n][h];
	}
	

	if (n == h && n < 2)
	{
		return 1;
	}
	
	if (n < h)
	{
		return 0;
	}
	
	
	
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += dfs(i - 1, h - 1) * dfs(n - i, 0) + dfs(n - i, h - 1) * dfs(i - 1, 0) - dfs(i - 1, h - 1) * dfs(n - i, h - 1);
	}
	
	d[n][h] = sum;
	
	return sum;
}

int main()
{
	int n, h;
	cin >> n >> h;

	memset(d, -1, sizeof(d));
	
	ll count = dfs(n, h);
	
	cout << count << endl;
	
	return 0;
}