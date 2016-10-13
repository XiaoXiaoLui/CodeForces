#include <iostream>



using namespace std;

#define N 100002
int a[N];

int main()
{
	int n;
	int sum = 0;
	int aliceSum = 0;
	int bobSum = 0;
	int aliceNum = 0;
	int bobNum = 0;
	cin >> n;
	
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	
	for (i = 0; i < n; i++)
	{
		aliceSum += a[i];
		
		if (aliceSum >= (double)sum / 2)
		{
			break;
		}
	}
	
	if (aliceSum == (double)sum / 2)
	{
		aliceNum = i;
	}
	else
	{
		if (aliceSum - a[i] <= sum - aliceSum)
		{
			aliceNum = i;
		}
		else
		{
			aliceNum = i - 1;
		}
	}
	
	aliceNum++;
	bobNum = n - aliceNum;
	
	cout << aliceNum << " " << bobNum << endl;
	
	return 0;
}