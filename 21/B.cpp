#include <iostream>


using namespace std;


int main()
{
	int a1, a2, b1, b2, c1, c2;
	int ans;
	cin >> a1 >> b1 >> c1;
	cin >> a2 >> b2 >> c2;
	
	if (!a1 && !b1 && c1 || !a2 && !b2 && c2)
	{
		ans = 0;
	}
	else if (a1*b2 - b1*a2 == 0)
	{
		if (c1*b2 - c2*b1 == 0 && c1*a2 - c2*a1 == 0)
		{
			ans = -1;
		}
		else
		{
			ans = 0;
		}
	}
	else
	{
		ans = 1;
	}
	
	cout << ans << endl;
	
	return 0;
}

