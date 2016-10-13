#include <cstdio>

int getColorKNum(int n, int m, int k)
{
	int res = 0, nk, mk;
	nk = n - 2*k;
	mk = m - 2*k;
	if (nk <= 0 || mk <= 0)
	{
		res = 0;
	}
	else
	{
		res = (nk*mk + 1) / 2;
	}
	return res;
}

int main()
{
	int n, m, k, mk, nk;
	scanf("%d%d%d", &n, &m, &k);
	k--;
	
	int ans = 0;
	ans = getColorKNum(n, m, k) - getColorKNum(n, m, k + 1);
	printf("%d\n", ans);
	
	
	return 0;
}