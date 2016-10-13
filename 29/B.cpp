#include <cstdio>



int main()
{
	int l, d, v, g, r;
	double ans;
	int p, q;
	scanf("%d%d%d%d%d", &l, &d, &v, &g, &r);
	
	p = d / v;
	q = d % v;
	ans = (double)d / v;
	int t = p % (g + r);
	if (t >= g)
	{
		ans += (g + r) - (t + (double)q / v);
	}
	
	ans += (double)(l - d) / v;
	
	printf("%.12lf\n", ans);
	
	return 0;
}