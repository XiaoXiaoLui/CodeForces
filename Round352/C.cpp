#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Position
{
	double x;
	double y;
};

double dist(const Position &a, const Position &b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

struct Info
{
	int index;
	double dist;
	
	bool operator < (const Info &other) const
	{
		return dist < other.dist;
	}
};

const int N = 100005;


double da;
double db;
double dt;

Info infoA[N];
Info infoB[N];
Position bottle[N];

int main()
{
	int n, i;
	Position a, b, t;
	double ans = 0;
	
	cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y >> n;
	
	double minDiff = 0;

	for (i = 0; i < n; i++)
	{
		cin >> bottle[i].x;
		cin >> bottle[i].y;
		
		dt = dist(bottle[i], t); 
		da = dist(bottle[i], a);
		db = dist(bottle[i], b);
		
		ans += 2*dt;
		
		infoA[i].dist = da - dt;
		infoB[i].dist = db - dt;
		infoA[i].index = infoB[i].index = i;	
	}
	
	sort(infoA, infoA + n);
	sort(infoB, infoB + n);
	
	minDiff = infoA[0].dist;
	
	minDiff = min(minDiff, infoB[0].dist);
	if (infoA[0].index != infoB[0].index)
	{
		minDiff = min(minDiff, infoA[0].dist + infoB[0].dist);
	}
	
	if (n >= 2)
	{
		minDiff = min(minDiff, infoA[0].dist + infoB[1].dist);
		minDiff = min(minDiff, infoA[1].dist + infoB[0].dist);
	}
	
	ans += minDiff;
	
	cout.setf(ios::fixed);
	cout.precision(8);
	cout << ans << endl;
	
	return 0;
}