#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 1000002;

char bArray[N];
int nArray[N];
char tmpArray[N];

void dec(int *array, int &len)
{
	int i = 0;
	
	for (i = 0; i < len && array[i] == 0; i++)
	{
		array[i] = 9;
	}
	
	array[i]--;
	
	if (array[len - 1] == 0)
	{
		len--;
	}
}


ll exp(ll a, int b, ll md)
{
	ll ret = 1;
	
	for (int i = 0; i < b; i++)
	{
		ret = (ret * a) % md;
	}
	
	return ret;
}


int main()
{
	int lenB, lenN, i;
	ll c, b, ans = 1;
	
	
	cin >> bArray;
	
	cin >> tmpArray;
	lenN = strlen(tmpArray);
	for (i = 0; tmpArray[i]; i++)
	{
		nArray[lenN - 1 - i] = tmpArray[i] - '0';
	}
	
	cin >> c;
	b = 0;
	for (i = 0; bArray[i]; i++)
	{
		b = (b * 10 + bArray[i] - '0') % c;
	}
	
	dec(nArray, lenN);
	
	ll expB = b;
	for (i = 0; i < lenN; i++)
	{
		ans = (ans * exp(expB, nArray[i], c)) % c;
		expB = exp(expB, 10, c);
	}
	
	ans = (ans * (b - 1)) % c;
	if (ans == 0)
	{
		ans = c;
	}
	if (ans < 0)
	{
		ans += c;
	}
	
	cout << ans << endl;
	
	
	
	
	return 0;
}