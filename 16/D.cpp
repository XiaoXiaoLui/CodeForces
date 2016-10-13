#include <iostream>
#include <string>


using namespace std;

int getTime(char *msg)
{
	int h, m, time;
	
	h = (msg[1] - '0') * 10 + (msg[2] - '0');
	m = (msg[4] - '0') * 10 + (msg[5] - '0');
	
	if (msg[7] == 'p')
	{
		h += 12;
	}
	time = 60 * h + m;
	
	return time;
}

int main()
{
	int n, i;
	char msg[100];
	int preTime;
	int curTime;
	int multiCount = 0;
	int ans = 0;
	
	cin >> n;
	cin.getline(msg, sizeof(msg));
	preTime = 24 * 60 + 1;
	for (i = 1; i <= n; i++)
	{
		cin.getline(msg, sizeof(msg));
		curTime = getTime(msg);
		if (curTime < preTime)
		{
			multiCount = 1;
			ans++;
		}
		else if (curTime == preTime)
		{
			multiCount++;
			if (multiCount > 10)
			{
				ans++;
				multiCount = 1;
			}
		}
		else 
		{
			multiCount = 1;
		}
		
		preTime = curTime;
	}
	
	cout << ans << endl;
}