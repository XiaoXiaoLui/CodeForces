#include <iostream>
#include <set>

using namespace std;



#define N 502


int f[N][N][3];
int a1[N];
int a2[N];
int len1;
int len2;

struct Info
{
	int i;
	int j;
	int len;
	int e;
	
	bool operator < (const Info &other) const
	{
		bool ret = false;
		
		if (len < other.len)
		{
			ret = true;
		}
		else if (len == other.len && (i*N + j) < (other.i*N + other.j))
		{
			ret = true;
		}
		
		return ret;
	}
};


int main()
{
	int i, j,k;
	set<Info> record;
	int st[N];
	int stLen;
	cin >> len1;
	
	for (i = 1; i <= len1; i++)
	{
		cin >> a1[i];
	}
	
	cin >> len2;
	
	for (i = 1; i <= len2; i++)
	{
		cin >> a2[i];
	}
	
	
	//f[0][0][0] = f[0][0][1] = f[0][0][2] = 0;
	set<Info>::reverse_iterator iter;
	int maxLen = 0;
	int maxI = 0;
	int maxJ = 0;
	for (i = 1; i <= len1; i++)
	{
		for (j = 1; j <= len2; j++)
		{
			if (a1[i] == a2[j])
			{
				for (iter = record.rbegin(); iter != record.rend(); iter++)
				{
					if ((*iter).e < a1[i] && (*iter).i < i && (*iter).j < j)
					{
						break;
					}
				}
				if (iter != record.rend())
				{
					f[i][j][0] = (*iter).len + 1;
					f[i][j][1] = (*iter).i;
					f[i][j][2] = (*iter).j;
				}
				else
				{
					f[i][j][0] = 1;
					f[i][j][1] = 0;
					f[i][j][2] = 0;
				}
				
				Info ele;
				ele.i = i;
				ele.j = j;
				ele.len = f[i][j][0];
				ele.e = a1[i];
				record.insert(ele);
				
				if (f[i][j][0] > maxLen)
				{
					maxLen = f[i][j][0];
					maxI = i;
					maxJ = j;
				}
			}
		}
	}
	
	stLen = maxLen;
	int tmpI;
	int tmpJ;
	for (i = maxI, j = maxJ, k = stLen; i != 0; k--)
	{
		st[k] = a1[i];
		tmpI = f[i][j][1];
		tmpJ = f[i][j][2];
		i = tmpI;
		j = tmpJ;
	}
	
	cout << stLen << endl;
	for (i = 1; i <= stLen; i++)
	{
		cout << st[i] << " ";
	}
	
	return 0;
}