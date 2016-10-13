#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main()
{
	set<double> ans;
	double a, b, c, delta, root;
	bool infinite = false;
	
	cin >> a >> b >> c;
	
	if (a == 0 && b == 0)
	{
		if (c == 0)
		{
			infinite = true;
		}
	}
	else if (a == 0)
	{
		root = -c / b;
		ans.insert(root);
	}
	else
	{
		delta = b*b - 4 * a * c;
		
		if (delta < 0)
		{
			
		}
		else if (delta == 0)
		{
			root = -b / (2 * a);
			ans.insert(root);
		}
		else
		{
			root = (-b + sqrt(delta)) / (2 * a);
			ans.insert(root);
			root = (-b - sqrt(delta)) / (2 * a);
			ans.insert(root);
		}
	}
	
	
	cout.setf(ios::fixed);
	cout.precision(7);
	
	if (infinite)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans.size() << endl;
		
		for (set<double>::iterator iter = ans.begin(); iter != ans.end(); iter++)
		{
			cout << *iter << endl;
		}
	}
	
	return 0;
}