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

const int N = 1e5 + 100;
char ans[N];
char color[2];

int main()
{
	// USE_IOSTREAM;
	int n, k, a, b, i, j, num, restA;
	cin >> n >> k >> a >> b;
	
	
	color[0] = 'G';
	color[1] = 'B';
	
	if (a < b)
	{
		swap(a, b);
		swap(color[0], color[1]);
	}
	
	num = (a + k - 1) / k - 1;
	if (b < num)
	{
		cout << "NO" << endl;
		return 0;
	}
	
	restA = a - num * k;
	
	b -= num;
	
	int idx = 0;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < k; j++)
		{
			ans[idx++] = color[0];
		}
		
		ans[idx++] = color[1];
		for (j = 1; j < k && b > 0; j++, b--)
		{
			ans[idx++] = color[1];
		}
	}
	
	for (j = 0; j < restA; j++)
	{
		ans[idx++] = color[0];
	}
	for (j = 0; j < b; j++)
	{
		ans[idx++] = color[1];
	}
	ans[n] = '\0';
	
	cout << ans << endl;
	
	
	return 0;
}