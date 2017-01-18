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
int a[N];

int main()
{
	// USE_IOSTREAM;
	int n, n1, n2, i;
	scanf("%d%d%d", &n, &n1, &n2);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	if (n2 < n1)
	{
		swap(n1, n2);
	}
	
	sort(a, a + n, greater<int>());
	double ans = 0;
	double sum = 0;
	double sum1 = 0;
	for (i = 0; i < n1 + n2; i++)
	{
		sum += a[i];
	}
	for (i = 0; i < n1; i++)
	{
		sum1 += a[i];
	}
	
	ans = ((n2 - n1) * sum1 + n1 * sum) / n1 / n2;
	
	printf("%.9lf\n", ans);
	
	return 0;
}