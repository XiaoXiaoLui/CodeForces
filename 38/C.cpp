#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;
int a[N];

int main()
{
	int n, minLen, i, len, maxLen;
	scanf("%d%d", &n, &minLen);
	maxLen = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		maxLen = max(maxLen, a[i]);
	}
	
	int ans = 0;
	for (len = minLen; len <= maxLen; len++)
	{
		int curArea = 0;
		for (i = 0; i < n; i++)
		{
			curArea += a[i] / len;
		}
		curArea *= len;
		
		ans = max(ans, curArea);
	}
	printf("%d\n", ans);
	
	
	return 0;
}