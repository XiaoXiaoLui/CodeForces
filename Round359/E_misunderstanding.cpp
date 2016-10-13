#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

//#define LLD "%l" "ld"
#define LLD "%I64d"

typedef long long ll;

#define pii pair<int, int>
#define mp make_pair<int, int>

const int N = 1e5 + 5;

ll x[N];
ll y[N];
ll z[N];
vector<ll> ansX;
vector<ll> ansY;
vector<ll> ansZ;
int main()
{
	int n, t, i, k;
	scanf("%d", &t);
	for (k = 0; k < t; k++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf(LLD LLD LLD, &x[i], &y[i], &z[i]);
		}
		sort(x, x + n);
		sort(y, y + n);
		sort(z, z + n);
		ansX.push_back(x[n/2]);
		ansY.push_back(y[n/2]);
		ansZ.push_back(z[n/2]);
	}
	
	for (i = 0; i < t; i++)
	{
		printf(LLD " " LLD " " LLD "\n", ansX[i], ansY[i], ansZ[i]);
	}
	

	return 0;
}
