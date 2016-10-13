#include <iostream>

using namespace std;

int main()
{
	int n, t, ans;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		ans = n > 2 ? n - 2 : 0;
		cout << ans << endl;
	}
	
	return 0;
}