#include <iostream>
#include <cmath>

using namespace std;

#define N 102
#define BIGNUM 99999999

int main()
{
	int n, vb, vs;
	double s[N];
	double x, y;
	int i;
	int bestIndex = 0;
	double bestTime = (double)BIGNUM;
	double bestDist = (double)BIGNUM;
	
	
	cin >> n >> vb >> vs;
	
	for (i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	
	cin >> x >> y;
	
	double time = 0;
	double dist = 0;
	for (i = 2; i <= n; i++)
	{
		dist = sqrt((x - s[i])*(x - s[i]) + y*y);
		time = s[i] / vb + dist / vs;
		
		if (time <= bestTime)
		{
			if (time < bestTime || dist < bestDist)
			{
				bestIndex = i;
				bestTime = time;
				bestDist = dist;
			}
		}
	}
	
	cout << bestIndex << endl;
	
	return 0;
}