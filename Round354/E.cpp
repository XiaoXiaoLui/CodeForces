#include <iostream>
#include <climits>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long ll;

const int N = 100005;
int n, k;
int a[N];

const int M = 4;

const ll P[M] = {585847,  908113,  991703, 999853};
ll S[M];
ll EXP[M] = {1, 1, 1};


int main()
{
	int i, j, count = 0;
	char str[10];
	cin >> n >> k;
	bool ans;

	for (i = 0; i <= n; i++)
	{
		cin >> str;
		
		if (!strcmp(str, "?"))
		{
			count++;
			a[i] = INT_MAX;
		}
		else
		{
			a[i] = atoi(str);
		}
	}
	
	if (k == 0)
	{
		if (a[0] == 0)
		{
			ans = true;
		}
		else if (a[0] != INT_MAX)
		{
			ans = false;
		}
		else if ((n + 1 - count) & 1)
		{
			ans = true;
		}
		else
		{
			ans = false;
		}
	}
	else if (count != 0)
	{	
		if ((n + 1) & 1)
		{
			ans = false;
		}
		else
		{
			ans = true;
		}
	}
	else
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j < M; j++)
			{
				S[j] = (S[j] + EXP[j] * a[i]) % P[j];
				EXP[j] = (EXP[j] * k) % P[j];
			}				
		}
		
		ans = true;
		for (j = 0; j < M; j++)
		{
			if (S[j])
			{
				ans = false;
				break;
			}
		}
	}
	
	if (ans)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}