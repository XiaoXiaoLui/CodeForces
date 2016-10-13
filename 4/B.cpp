#include <iostream>

using namespace std;

#define N 40

int dp[N][2];
int plan[N][2];
int day[N];

int main()
{
	int d, sumTime;
	
	cin >> d >> sumTime;
	
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= d; i++)
	{
		cin >> plan[i][0] >> plan[i][1];
		dp[i][0] = dp[i - 1][0] + plan[i][0];
		dp[i][1] = dp[i - 1][1] + plan[i][1];
	}
	
	bool bFail = false;
	int min, max;
	for (int i = d; i >= 1; i--)
	{
		min = sumTime - dp[i - 1][1];
		max = sumTime - dp[i - 1][0];
		
		if (min <= plan[i][1] && min >= plan[i][0])
		{
			day[i] = min;
		}
		else if (max <= plan[i][1] && max >= plan[i][0])
		{
			day[i] = max;
		}
		else if (min <= plan[i][0] && max >= plan[i][1])
		{
			day[i] = plan[i][1];
		}
		else
		{
			bFail = true;
			break;
		}
		
		sumTime -= day[i];
	}
	
	if (bFail)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
		for (int i = 1; i <= d; i++)
		{
			cout << day[i] << " ";
		}
	}
	
	return 0;
}