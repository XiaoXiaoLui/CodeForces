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
char s[N];

int main()
{
	// USE_IOSTREAM;
	int n, i, c1, c2;
	scanf("%d", &n);
	scanf("%s", s);
	
	for (i = c1 = c2 = 0; i < n; i++)
	{
		if (s[i] == 'A')
		{
			c1++;
		}
		else
		{
			c2++;
		}
	}
	
	
	if (c1 > c2)
	{
		printf("Anton\n");
	}
	else if (c1 == c2)
	{
		printf("Friendship\n");
	}
	else
	{
		printf("Danik\n");
	}
	
	return 0;
}