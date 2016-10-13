#include <iostream>
#include <climits>


using namespace std;

#define N 11
#define M 9

int getShots(int h, int c)
{
	int shots = 0;
	if (h >= 0)
	{
		shots = h / c + 1;
	}
	
	return shots;
}

void findBestRecur(int h[], int best[], int curPos, int curShots, int buf[], int &leastShots, int n, int a, int b)
{
	/*static int buf[N];
	static int curShots = 0;
	static int curPos = 2;*/
	
	int i = 0;
	int left, right, self, max, min;
	
	left = getShots(h[curPos - 1], b);
	right = getShots(h[curPos +1], b);
	self = getShots(h[curPos], a);
	
	if (curPos == n - 1)
	{
		max = (left >= right) ? left : right;
		max = max >= self ? max : self;
		
		if (curShots + max < leastShots)
		{
			leastShots = curShots + max;
			buf[curPos] = max;
			for (i = 2; i <= n - 1; i++)
			{
				best[i] = buf[i];
			}
		}
	}
	else
	{
		min = left;
		max = left >= self ? left : self;
		
		for (i = min; i <= max; i++)
		{
			h[curPos - 1] -= i * b;
			h[curPos] -= i * a;
			h[curPos + 1] -= i * b;
			buf[curPos] = i;
			findBestRecur(h, best, curPos + 1, curShots + i, buf, leastShots, n, a, b);
			
			// recover state
			h[curPos - 1] += i * b;
			h[curPos] += i * a;
			h[curPos + 1] += i * b;
		}
	}
}

void findBest(int h[], int best[], int &leastShots, int n, int a, int b)
{
	int buf[N];
	leastShots = INT_MAX;

	findBestRecur(h, best, 2, 0, buf, leastShots, n, a, b);
}

int main()
{
	int n, a, b;
	int i = 0;
	int j = 0;
	int leastShots = 0;
	
	int h[N];
	int best[N];
	
	cin >> n >> a >> b;
	
	for (i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
		
	findBest(h, best, leastShots, n, a, b);
	
	cout << leastShots << endl;
	for (i = 2; i <= n - 1; i++)
	{
		for (j = 0; j < best[i]; j++)
		{
			cout << i << " ";
		}
	}
	
	
	
	
	return 0;
}