#include <iostream>


using namespace std;

#define N 2000002

char a[N];
char b[N];
char c[N];

int d[N];
double f[N][2];


int main()
{
	int n = 0;
	int m = 0;
	int i, j, k;
	
	cin >> a;
	
	int correct = 0;
	c[0] = 0;

	for (i = 0, j = 0, k = 1; a[i] != '\0'; i++, j++)
	{
		b[j] = a[i];
		
		if (b[j] != 'X' && a[i + 1] != '\0')
		{
			c[k] = j + 1;
			d[k - 1] = c[k] - c[k - 1];
			k++;
		}
		
		if (a[i] != 'X' && a[i] == a[i + 1])
		{
			j++;
			b[j] = 'X';
		}
		

	}
	m = k;
	n = j;
	
	for (i = c[m - 1]; i < n && b[i] == 'X'; i++);
	
	if (i >= n)
	{
		m--;
	}
	
	
	for (i = m - 1; i >= 0; i--)
	{
		if (d[i]
	}
	

	
	
	
	double rate = ((double)(correct * 100)) / len;
	rate = (double)(int(rate * 1000000)) / 1000000;
	

	
	//cout << b << endl;
	
	cout.setf(ios::fixed);
	cout.precision(6);
	cout << rate << endl;
	
	
}