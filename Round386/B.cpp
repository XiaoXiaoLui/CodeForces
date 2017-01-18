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

const int N = 2500;
char a[N];
char b[N]; 

int main()
{
	// USE_IOSTREAM;
	int n, i;
	scanf("%d", &n);
	scanf("%s", b);
	
	int l, r;
	int dir = n % 2;
	
	if (dir)
	{
		r = (n - 1) / 2;
		l = r - 1;
	}
	else
	{
		l = (n - 1) / 2;
		r = l + 1;
	}
	for (i = 0; i < n; i++)
	{
		if (dir)
		{
			a[r++] = b[i];
		}
		else
		{
			a[l--] = b[i];
		}
		dir = 1 - dir;
	}
	
	a[n] = '\0';
	printf("%s\n", a);
		
	
	return 0;
}