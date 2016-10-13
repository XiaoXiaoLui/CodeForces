#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	unsigned long long m, n, a;
	
	cin >> n >> m >> a;
	
	unsigned long long row, col;
	
	row = (n % a) ? (n / a + 1) : (n / a);
	col = (m % a) ? (m / a + 1) : (m / a);
	
	cout << row * col << endl;
	
}