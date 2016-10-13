#include <iostream>

using namespace std;

int main()
{
	int n;
	int min, max;
	
	cin >> n;
	
	int q = n / 7;
	int r = n % 7;
	
	min = q*2 + (r == 6 ? 1 : 0);
	max = q*2 + (r >= 2 ? 2 : r);
	
	cout << min << " " << max << endl;
	
	return 0;
}