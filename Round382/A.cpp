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


char s[200];


int main()
{
	// USE_IOSTREAM;
	int n, i, start, end, k;
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for (i = 0; i < n; i++)
	{
		if (s[i] == 'G')
		{
			start = i;
		}
		else if (s[i] == 'T')
		{
			end = i;
		}
	}
	
	if (start < end)
	{
		for (i = start; i < end; i += k)
		{
			if (s[i] == '#')
			{
				break;
			}
		}
	}
	else
	{
		for (i = start; i > end; i -= k)
		{
			if (s[i] == '#')
			{
				break;
			}
		}
	}
	
	if (i == end)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	return 0;
}