#include <iostream>

using namespace std;

typedef long long ll;


int main()
{
	int n, a, b, c, d, left, right, i, minSum, maxSum;
	ll ans = 0;
	int s1, s2, s3, s4;
	
	cin >> n >> a >> b >> c >> d;
	
	for (i = 1; i <= n; i++)
	{
		s1 = i + a + b;
		s2 = i + b + d;
		s3 = i + d + c;
		s4 = i + c + a;
		
		left = min(min(s3,min(s1, s2)), s4);
		right = max(max(s3, max(s1, s2)), s4);
		minSum = right + 1;
		maxSum = left + n;
		
		if (maxSum >= minSum)
		{
			ans += maxSum - minSum + 1;
		}
	}
	
	cout << ans << endl;
	
	
	
	return 0;
}