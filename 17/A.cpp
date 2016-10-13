#include <iostream>

using namespace std;

const int N = 1001;
bool prime[N];

int main()
{
	int n, k, i, j, count = 0, p;
	
	cin >> n >> k;
	
	for (i = 2; i <= n; i++)
	{
		prime[i] = true;
	}
	
	for (i = 2; i <= n; i++)
	{
		if (!prime[i])
		{
			continue;
		}
		
		for (j = i + i; j <= n; j += i)
		{
			prime[j] = false;
		}
		
		for (j = 2; j < i; j++)
		{
			if (!prime[j])
			{
				continue;
			}
			for (p = j + 1; p < i && !prime[p]; p++);
			
			if (p < i && i == j + p + 1)
			{
				count++;
			}
		}
	}
	
	if (count >= k)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}