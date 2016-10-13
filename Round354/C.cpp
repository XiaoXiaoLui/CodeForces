#include <iostream>

using namespace std;

const int N = 100005;

char str[N];
int sumA[N];
int sumB[N];
int n, k;

int find(int sum[], int i)
{
	int len, l = i, r = n, mid;
	
	if (k == 0 && sum[i] - sum[i - 1] > 0)
	{
		return 0;
	}
	
	while (r - l > 1)
	{
		mid = (l + r) / 2;
		if (sum[mid] - sum[i - 1] <= k)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	
	return (l - i + 1);
}

int main()
{
	int i, j, ans = 0, cur;
	
	cin >> n >> k;
	
	cin >> str + 1;
	
	for (i = 1; str[i] != '\0'; i++)
	{
		if (str[i] == 'a')
		{
			sumA[i] = sumA[i - 1] + 1;	
			sumB[i] = sumB[i - 1];
		}
		else
		{
			sumA[i] = sumA[i - 1];
			sumB[i] = sumB[i - 1] + 1;
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		if (sumB[n] - sumB[i - 1] <= k)
		{
			ans = max(ans, n - i + 1);
			break;
		}
		ans = max(ans, find(sumB, i));
		
	}
	
	for (i = 1; i <= n; i++)
	{
		if (sumA[n] - sumA[i - 1] <= k)
		{
			ans = max(ans, n - i + 1);
			break;
		}
		ans = max(ans, find(sumA, i));
	}
	
	cout << ans << endl;
	
	return 0;
}