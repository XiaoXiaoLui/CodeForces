#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define LLD "%l" "ld"

#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const double LOW_RATE = 0.8;
const double HIGH_RATE = 1.25;
const ll HIGH_RATE_A = 5;
const ll HIGH_RATE_B = 4;
const ll LOW_RATE_A = 4;
const ll LOW_RATE_B = 5;


int main()
{
	int H, W, h, w;
	ll maxArea = 0LL, a;
	pii ans;
	scanf("%d%d", &H, &W);
	for (h = 1; h <= H; h *= 2)
	{
		w = min((int)(h / LOW_RATE) - 1, W);
		for (; w < W && h *LOW_RATE_B >= (w + 1) * LOW_RATE_A; w++);
		
		if (h * LOW_RATE_B < w * LOW_RATE_A || h * HIGH_RATE_B > w * HIGH_RATE_A)
		{
			break;
		}
		
		a = (ll)w * h;
		if (a > maxArea || ((a == maxArea) && h > ans.first))
		{
			maxArea = a;
			ans = mp(h, w);
		}
	}
	
	for (w = 1; w <= W; w *= 2)
	{
		h = min((int)(w * HIGH_RATE) - 1, H);
		for (; h < H && (h + 1) * HIGH_RATE_B <= w * HIGH_RATE_A; h++);
		
		if (h * LOW_RATE_B < w * LOW_RATE_A || h * HIGH_RATE_B > w * HIGH_RATE_A)
		{
			break;
		}
		
		a = (ll)w*h;
		if (a > maxArea || ((a == maxArea) && h > ans.first))
		{
			maxArea = a;
			ans = mp(h, w);
		}
	}
	
	
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}