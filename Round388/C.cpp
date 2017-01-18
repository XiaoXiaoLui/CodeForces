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

const int N = 2e5 + 100;
char s[N];

int main()
{
	//USE_IOSTREAM;
	set<int> SD;
	set<int> SR;
	
	int n, i;
	scanf("%d", &n);
	scanf("%s", s);
	for (i = 0; i < n; i++)
	{
		if (s[i] == 'D')
		{
			SD.insert(i);
		}
		else
		{
			SR.insert(i);
		}
	}
	
	while (!SD.empty() && !SR.empty())
	{
		for (i = 0; i < n && (!SD.empty() && !SR.empty()); i++)
		{
			if (s[i] == 'D')
			{
				auto iter = SR.upper_bound(i);
				if (iter == SR.end())
				{
					iter = SR.begin();
				}
				s[*iter] = 'E';
				SR.erase(iter);
			}
			else if (s[i] == 'R')
			{
				auto iter = SD.upper_bound(i);
				if (iter == SD.end())
				{
					iter = SD.begin();
				}
				s[*iter] = 'E';
				SD.erase(iter);
			}
		}
	}
	
	if (SD.empty())
	{
		printf("R\n");
	}
	else
	{
		printf("D\n");
	}
	
	return 0;
}