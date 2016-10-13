// c++ 11
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 2000002;
const ll MD =  51123987;

char str[2 * N + 1];
int lenArray[2 * N + 1];
int a[N];
int start[N];
int finish[N];


// *2 /2 cin
int main()
{
	int n, i, c, r,lc, lr;
	ll ans;
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> str[i + i];
	}
	
	
	for (lc = -1, lr = -1, c = 0, r = 0; c < 2*n - 1; c++)
	{
		r = c;
		if (lr > c)
		{
			r = min(lr, c + lenArray[2*lc - c]);
		}
		
		while (r + 1 < 2*n - 1 && 2*c - (r + 1) >= 0 && str[r + 1] == str[2*c - r - 1])
		{
			r++;
		}
		lenArray[c] = r - c;
		
		if (r > lr)
		{
			lr = r;
			lc = c;
		}
	}
	
	for (i = 0; i < 2*n - 1; i++)
	{		
		a[(i - lenArray[i] + 1) / 2]++;
		a[i / 2 + 1]--;
	}
	
	start[0] = a[0];
	for (i = 1; i < n; i++)
	{
		start[i] = start[i - 1] + a[i];
	}
	
	memset(a, 0, sizeof(a));
	for (i = 0; i < 2*n - 1; i++)
	{
		a[(i + lenArray[i]) / 2]++;
		a[(i + 1) / 2 - 1]--;
	}
	
	finish[n - 1] = a[n - 1];
	for (i = n - 2; i >= 0; i--)
	{
		finish[i] = finish[i + 1] + a[i];
	}
	
	for (i = 0, ans = 0; i < 2*n - 1; i++)
	{
		if (i % 2)
		{
			ans += (lenArray[i] + 1) / 2;
		}
		else
		{
			ans += lenArray[i] / 2 + 1;
		}
	}
	
	ans %= MD;
	ans = (ans * (ans - 1) / 2) % MD;
	
	ll sum = 0;
	for (i = 0; i < n; i++)
	{
		ans = (ans - sum * start[i]) % MD;
		sum = (sum + finish[i]) % MD;
	}

	ans = (ans + MD) % MD;
	cout << ans << endl;
}
