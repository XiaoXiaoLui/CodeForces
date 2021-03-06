#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
const int M = 350;

struct Block
{
	Block()
	{
		maxValue = 0;
	}
	vector<int> vec;
	int maxValue;
};

Block b[N];
int blockSize = 1;

void reconstruct()
{
	int i, j, maxValue;
	vector<int> tmp;
	for (i = 0; i < blockSize; i++)
	{
		tmp.insert(tmp.end(), b[i].vec.begin(), b[i].vec.end());
		b[i].vec.clear();
	}
	
	j = 0;
	maxValue = 0;
	for (i = 0; i < tmp.size(); i++)
	{
		b[j].vec.push_back(tmp[i]);
		maxValue = max(maxValue, tmp[i]);
		if (b[j].vec.size() == M)
		{
			b[j].maxValue = maxValue;
			j++;
			maxValue = 0;
		}
	}
	blockSize = j + 1;
}

void insert(int a, int c)
{
	int i;
	i = blockSize - 1;
	while (i >= 0)
	{
		if (c > b[i].vec.size() && a > b[i].maxValue && i)
		{
			c -= b[i].vec.size();
			i--;
		}
		else
		{
			vector<int>::reverse_iterator iter;
			for (iter = b[i].vec.rbegin(); iter != b[i].vec.rend() && c > 0 && *iter < a; iter++, c--);
			b[i].vec.insert(iter.base(), a);
			b[i].maxValue = max(b[i].maxValue, a);
			break;
		}
	}
}

int index[N];

int main()
{
	int n, i, j, a, c;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &c);
		index[a] = i + 1;
		insert(a, c);
		if ((i + 1) % M == 0)
		{
			reconstruct();
		}
	}
	
	for (i = 0; i < blockSize; i++)
	{
		for (j = 0; j < b[i].vec.size(); j++)
		{
			printf("%d ", index[b[i].vec[j]]);
		}
	}
	printf("\n");
	
	return 0;
}