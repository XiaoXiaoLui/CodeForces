#include <iostream>
#include <climits>
#include <cmath>

//#define MYDEBUG

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


// for debug
#ifdef MYDEBUG
double f[N][K];
double e[K][K];
const double ERROR = 0.00001;
#endif


double getInterSection(const Line &line1, const Line &line2)
{
	double x = 0;
	
	if (line1.a == line2.a)
	{
		cout << "ERROR in getIntersection" << endl;
	}
	else
	{
		x = (line2.b - line1.b) / (line1.a - line2.a);
	}
	
	return x;
}

void addLine(double a, double b)
{
	Line newLine;
	newLine.a = a;
	newLine.b = b;
	double x;
	while (lineCount != 0)
	{
		x = getInterSection(lines[lineCount - 1], newLine);
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

double getMinY(double x)
{
	int left = 0;
	int right = lineCount - 1;
	
	int mid;
	
	if (x >= lines[right].x)
	{
		return (lines[right].a * x + lines[right].b);
	}
	
	while (right - left > 1)
	{
		mid = (right + left) / 2;
		
		if (x <= lines[mid].x)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	
	return (lines[left].a * x + lines[left].b);
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
	
	
	// for debug
#ifdef MYDEBUG
	for (i = 1; i <= n; i++)
	{
		double c = 0;
		for (j = i; j <= n; j++)
		{
			c += t[j];
			e[i][j] = e[i][j - 1] + c / t[j];
		}
		f[i][1] = e[1][i];
	}
	
	for (l = 2; l <= k; l++)
	{
		for (i = l; i <= n; i++)
		{
			f[i][l] = (double)INT_MAX;
			for (j = l - 1; j < i; j++)
			{
				f[i][l] = min(f[i][l], f[j][l - 1] + e[j + 1][i]);
			}
		}
	}
#endif
	
	cout.setf(ios::fixed);
	cout.precision(6);
	for (i = 1; i <= n; i++)
	{
		dp[i][1] = pre[i];
		
		#ifdef MYDEBUG
		if (abs(dp[i][1] - f[i][1]) > ERROR)
		{
			cout << "ERROR1: " << i << " " << dp[i][1] << " " << f[i][1] << endl;
		}
		#endif
	}
	
	// use convex hull trick to optimize dp
	for (l = 2; l <= k; l++)
	{			
		lineCount = 0;
		//curIndex = 0;
		for (i = l; i <= n; i++)
		{			
			a = -sum[i - 1];
			b = dp[i - 1][l - 1] - pre[i - 1] + rev[i - 1]*sum[i - 1];
			addLine(a, b);
			
			dp[i][l] = getMinY(rev[i]) + pre[i];
			
			#ifdef MYDEBUG
			if (abs(dp[i][l] - f[i][l]) > ERROR)
			{
				cout << "ERROR2:dp( " << i << ", " << l << ")  " << dp[i][l] << " " << f[i][l] << endl;;
			}
			#endif
		}
	}
	

	cout << dp[n][k];
	
	return 0;
}

