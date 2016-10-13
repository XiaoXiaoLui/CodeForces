#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

int a[105];
vector<int> ans;

int main()
{
	int sum = 0, n, i, j, w, minN = 2e9, minIndex;
	bool ok = true;
	
	scanf("%d%d", &n, &w);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < minN)
		{
			minN = a[i];
			minIndex = i;
		}
		sum += a[i];
	}
	
	if (n == 1)
	{
		if (w != sum)
		{
			ok = false;
		}
		else
		{
			for (i = 1; i <= sum; i++)
			{
				ans.push_back(1);
				ans.push_back(1);
			}
		}
	}
	else if (w > sum || w < 1)
	{
		ok = false;
	}
	else if (w == 1)
	{
		if (minN == 1)
		{
			ans.push_back(minIndex);
			for (i = 1; i <= n; i++)
			{
				if (i == minIndex)
				{
					continue;
				}
				for (j = 1; j <= a[i]; j++)
				{
					ans.push_back(i);
					ans.push_back(i);
				}
			}
			ans.push_back(minIndex);
		}
		else
		{
			ok = false;
		}
	}
	else
	{
		vector<int> tmp;
		for (i = 1; i <= n && w > 2; i++)
		{
			for (; a[i] > 1 && w > 2; w--, a[i]--)
			{
				tmp.push_back(i);
				tmp.push_back(i);
			}
		}
		
		for (i = n; w > 2; i--, w--)
		{
			tmp.push_back(i);
			tmp.push_back(i);
			a[i]--;
		}
		
		
		ans.push_back(2);
		while (a[1] > 1)
		{
			ans.push_back(1);
			ans.push_back(1);
			a[1]--;
		}
		ans.push_back(2);
		a[2]--;
		
		ans.push_back(1);
		for (i = 2; i <= n; i++)
		{
			for (j = 1; j <= a[i]; j++)
			{
				ans.push_back(i);
				ans.push_back(i);
			}
		}
		ans.push_back(1);
		
		for (i = 0; i < tmp.size(); i++)
		{
			ans.push_back(tmp[i]);
		}
	}
	
	if (ok)
	{
		printf("Yes\n");
		
		for (i = 0; i < ans.size(); i++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	else
	{
		printf("No\n");
	}
	
	return 0;
}