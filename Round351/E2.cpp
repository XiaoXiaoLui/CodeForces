#include <iostream>
#include <climits>
#include <cmath>


using namespace std;

typedef long long ll;

// y = ax + b
struct Line
{
	double a;
	double b;
	double x;	// intersection with previous line
};


const int N = 200004;
const int K = 55;
const double MIN_X = -999999999999.0;

double t[N];
double dp[N][K];
double pre[N];
double sum[N];
double rev[N];

Line lines[N];
int lineCount;



void addLine(double a, double b)
{
	Line newLine;
	newLine.a = a;
	newLine.b = b;
	double x;
	while (lineCount != 0)
	{
		x = (lines[lineCount - 1].b - newLine.b) / (newLine.a - lines[lineCount - 1].a);
		if (x <= lines[lineCount - 1].x)
		{
			lineCount--;
		}
		else
		{
			newLine.x = x;
			lines[lineCount++] = newLine;
			break;
		}
	} 
	
	if (lineCount == 0)
	{
		newLine.x = MIN_X;
		lines[lineCount++] = newLine;
	}
}


int main()
{
	int n, k, i, j, l, x, curIndex;
	double a, b;
	
	cin >> n >> k;
	
	for (i = 1; i <= n; i++)
	{
		cin >> t[i];
	}
	
	double c = 0;
	for (i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + t[i];
		rev[i] = rev[i - 1] + 1.0 / t[i];
		
		pre[i] = pre[i - 1] + sum[i] / t[i];
	}
	
	
	cout.setf(ios::fixed);
	cout.precision(6);
	for (i = 1; i <= n; i++)
	{
		dp[i][1] = pre[i];
		
	}
	
	// use convex hull trick to optimize dp
	int bestIndex;
	for (l = 2; l <= k; l++)
	{			
		lineCount = 0;
		bestIndex = 0;
		for (i = l; i <= n; i++)
		{			
			a = -sum[i - 1];
			b = dp[i - 1][l - 1] - pre[i - 1] + rev[i - 1]*sum[i - 1];
			addLine(a, b);
			
			if (bestIndex >= lineCount - 1)
			{
				bestIndex = lineCount - 1;
			}
			else
			{
				for (; bestIndex < lineCount - 1 && rev[i] > lines[bestIndex + 1].x; ++bestIndex);
			}
			
			dp[i][l] = lines[bestIndex].a * rev[i] + lines[bestIndex].b + pre[i];
			
		}
	}
	

	cout << dp[n][k];
	
	return 0;
}

