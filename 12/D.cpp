#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 500005;

struct Lady
{
	int x;
	int y;
	int z;
	int cy;
	
};



Lady lady[N];
int n;
int t[N]; // Fenwick tree
int index[N]; // for efficiency, sort index instead of lady

bool cmpy(const int &i, const int &j)
{
	return lady[i].y > lady[j].y;
}

bool cmp(const int &i, const int &j)
{
	return (lady[i].x > lady[j].x || (lady[i].x == lady[j].x && lady[i].y < lady[j].y));
}

inline int lowbit(int i)
{
	return i & -i;
}

int getMax(int i)
{
	int z = -1;
	
	while (i)
	{
		z = max(z, t[i]);
		i -= lowbit(i);
	}
	
	return z;
}

void insert(int i, int z)
{
	while (i <= n)
	{
		t[i] = max(t[i], z);
		i += lowbit(i);
	}
}


int main()
{
	int i, ans = 0;
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &lady[i].x);
	}
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &lady[i].y);
	}
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &lady[i].z);
		index[i] = i;
		t[i] = INT_MIN;
	}
	
	
	sort(index + 1, index + 1 + n, cmpy);
	
	lady[index[1]].cy = 1;
	for (i = 2;i <= n; i++)
	{
		lady[index[i]].cy = lady[index[i - 1]].cy + (lady[index[i - 1]].y > lady[index[i]].y);
	}
	
	sort(index + 1, index + 1 + n, cmp);
	int maxZ;
	for (i = 1;i <= n; i++)
	{
		maxZ = getMax(lady[index[i]].cy - 1);
		if (maxZ > lady[index[i]].z)
		{
			ans++;
		}
		insert(lady[index[i]].cy, lady[index[i]].z);
	}
	
	printf("%d\n", ans);
	
	return 0;
}