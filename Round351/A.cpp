#include <iostream>

using namespace std;

const int N = 92;



int main()
{
	int n;
	int a, b, ans;
	bool flag = false;
	cin >> n;
	
	a = 0;
	ans = 90;
	for (int i = 0; i < n; i++)
	{
		cin >> b;
		
		if (b - a > 15)
		{
			ans = a + 15;
			flag = true;
			break;
		}
		a = b;
	}
	
	if (!flag)
	{
		ans = b + 15;
	}
	
	if (ans > 90)
	{
		ans = 90;
	}
	cout << ans << endl;
	
	return 0;
}