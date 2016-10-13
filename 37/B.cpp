#include <cstdio>
#include <vector>

#define PII pair<int, int>
#define mp make_pair<int, int>

using namespace std;

const int N = 1005;
struct Spell
{
	int pow;
	int dmg;
};

Spell a[N];
bool used[N];
vector<PII> ans;

int main()
{
	int maxH, reg, n, i, pow, dmg, curH, t, dps, bestIndex, bestDmg;
	scanf("%d%d%d", &n, &maxH, &reg);
	
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &pow, &dmg);
		a[i].dmg = dmg;
		a[i].pow = maxH * pow / 100;
	}
	
	// just simulate the game
	curH = maxH;
	t = 0;
	dps = -reg;
	while (curH > 0)
	{
		bestDmg = 0;
		bestIndex = 0; // just no spell possible
		for (i = 1; i <= n; i++)
		{
			if (used[i])
			{
				continue;
			}
			if (curH <= a[i].pow && a[i].dmg > bestDmg)
			{
				bestIndex = i;
				bestDmg = a[i].dmg;
			}
		}
		
		used[bestIndex] = true;
		dps += bestDmg;
		
		if (dps <= 0 && bestIndex == 0)
		{
			break;
		}
		
		if (bestIndex != 0)
		{
			ans.push_back(mp(t, bestIndex));
		}
		
		curH -= dps;
		if (curH > maxH)
		{
			curH = maxH;
		}
		
		t++;
	}
	
	if (curH <= 0)
	{
		printf("YES\n");
		printf("%d %d\n", t, ans.size());
		for (i = 0; i < ans.size(); i++)
		{
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
	else
	{
		printf("NO\n");
	}
}