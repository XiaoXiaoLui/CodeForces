#include <iostream>
#include <algorithm>


using namespace std;

struct Envelope
{
	int seqNum;
	int w;
	int h;
	
	bool operator < (const Envelope &other)
	{
		if (w < other.w)
		{
			return true;
		}
		else if (w == other.w && h < other.h)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

#define N 5003

Envelope envelopes[N];
int dp[N][2];

int main()
{
	int n = 0;
	
	cin >> n;
	cin >> envelopes[0].w >> envelopes[0].h;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> envelopes[i].w >> envelopes[i].h;
		envelopes[i].seqNum = i;
	}
	
	sort(envelopes + 1, envelopes + n + 1);
	
	//dp[n + 1][0] = n + 1;
	//dp[n + 1][1] = 0;
	
	for (int i = n; i >= 0; i--)
	{
		dp[i][0] = n + 1;
		dp[i][1] = 1;
		for (int j = n; j > i; j--)
		{
			if (envelopes[i].w < envelopes[j].w && envelopes[i].h < envelopes[j].h
				&& dp[j][1] + 1 > dp[i][1])
			{
				dp[i][1] = dp[j][1] + 1;
				dp[i][0] = j;
			}
		}
	}
	
	if (dp[0][1] == 1)
	{
		cout << "0" << endl;
	}
	else
	{
		cout << dp[0][1] - 1 << endl;
		
		int i = 0;
		while (dp[i][0] != n + 1)
		{
			cout << envelopes[dp[i][0]].seqNum << " ";
			i = dp[i][0];
		}
	}
	
	return 0;
}