#include <cstdio>
#include <vector>
#include <algorithm>

//#define LDD "%ll" "d"
#define LDD "%I64d"

using namespace std;

typedef long long ll;

const int N = 1e6 + 5;
int h[N];
bool counted[N];
vector<int> vt;

int main()
{
	int n, i;
	
	scanf("%d", &n);
	
	ll ans = 0;
	int maxIndex = 0;
	int maxH = 0;
	int maxNum = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
		
		if (h[i] == maxH)
		{
			maxNum++;
		}
		else if (h[i] > maxH)
		{
			maxH = h[i];
			maxIndex = i;
			maxNum = 1;
		}
	}
	
	vt.push_back(maxH);
	vector<int>::reverse_iterator iter;
	for (i = (maxIndex + 1) % n; i != maxIndex; i = (i + 1) % n)
	{
		while (vt.back() < h[i])
		{
			vt.pop_back();
			ans++;
		}
		if (h[i] == vt.back())
		{
			iter = upper_bound(vt.rbegin(), vt.rend(), vt.back());
			if (iter == vt.rend())
			{
				ans += iter - vt.rbegin();
				counted[i] = true;
			}
			else
			{
				ans += iter - vt.rbegin() + 1;

				if (iter == vt.rend() - 1)
				{
					counted[i] = true;
				}
			}
		}
		else
		{
			ans++;
			if (vt.size() == 1)
			{
				counted[i] = true;
			}
		}
		
		vt.push_back(h[i]);
	}
	
	int curMax = 0;
	for (i = (maxIndex - 1 + n) % n; i != maxIndex; i = (i - 1 + n) % n)
	{
		if (h[i] >= curMax)
		{
			curMax = h[i];
			if (!counted[i])
			{
				ans++;
			}
		}
	}
	
	printf(LDD "\n", ans);
	
	return 0;
}

/* rotate */