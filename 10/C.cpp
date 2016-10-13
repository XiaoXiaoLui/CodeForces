#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	int n, i, j;
	ll sum = 0;
	//ll sumTest = 0;
	bool hasCal = false;
	
	cin >> n;
	
	for (i = 1; i <= n; i++)
	{
		hasCal = false;
		for (j = 1; j <= n; j++)
		{
			if (i * j <= n)
			{
				sum += (i * j - 1) / 9 + (n - i * j) / 9;
				//sumTest += (i * j - 1) / 9 + (n - i * j) / 9;
			}
			else if (n < 20) // just for simple code
			{
				sum += (i * j - 1) / 9 - (i * j - n - 1) / 9;
			}
			else 
			{

				int k = 0;
				ll num = n - j + 1;
				ll c1 = 0, c2 = 0, c3 = 0, c4 = 0;
				int r = ((n - 1) % 9) + 1;
				ll s1 = (n - 1) / 9 + 1;
				ll s2 = s1 - 1;
				for (k = j; k < j + num % 9; k++)
				{
					if (((i * k - 1) % 9) + 1 <= r)
					{
						c1++;
						c3++;
					}
					else
					{
						c2++;
						c4++;
					}
				}
				for (; k < j + 9; k++)
				{
					if (((i * k - 1) % 9) + 1 <= r)
					{
						c3++;
					}
					else
					{
						c4++;
					}
				}
				
				sum += s1 * c1 + s2 * c2;;
				sum += (s1 * c3 + s2 * c4) * (num / 9);
				break;
				//hasCal = true;
				
				//sumTest += (i * j - 1) / 9 - (i * j - n - 1) / 9;
			}
			
		}
		/*
		if (sum != sumTest)
		{
			cout << "ERROR " << i << " " << j << " " << sum << " " << sumTest << endl;
		}*/
	}
	
	
	cout << sum << endl;
	
	return 0;
}