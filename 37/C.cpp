#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int N = 1005;

struct Node
{
	Node()
	{
		id = 0;
		left = 0;
		right = 0;
		parent = 0;
		mark = 0;
	}
	int id;
	char mark;
	int left;
	int right;
	int parent;
};


Node tree[4 * N];
vector<int> a[N];
string code[N];


int main()
{
	int n, maxLen, i, j, len, start, end, curIndex, id;
	scanf("%d", &n);
	maxLen = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &len);
		a[len].push_back(i);
		maxLen = max(maxLen, len);
	}
	
	int count = 0;
	bool ok = true;
	for (i = maxLen; i >= 1; i--)
	{
		count += a[i].size();
		count = (count + 1) / 2;
	}
	
	if (count > 1)
	{
		ok = false;
	}
	if (ok)
	{
		start = 1;
		curIndex = 1;
		for (len = maxLen; len >= 1; len--)
		{
			for (i = 0; i < a[len].size(); i++)
			{
				tree[curIndex++].id = a[len][i];
			}
			end = curIndex;
			for (i = start; i < end; i++)
			{
				if ((i - start) % 2 == 0)
				{
					tree[curIndex].left = i;
					tree[i].parent = curIndex;
					tree[i].mark = '0';
					curIndex++;
				}
				else
				{
					tree[curIndex - 1].right = i;
					tree[i].parent = curIndex - 1;
					tree[i].mark = '1';
				}
			}
			start = end;
		}
	}
	
	for (i = 1; i < 4*N; i++)
	{
		if (!tree[i].id)
		{
			continue;
		}
		id = tree[i].id;
		curIndex = i;
		while (tree[curIndex].parent != 0)
		{
			code[id].push_back(tree[curIndex].mark);
			curIndex = tree[curIndex].parent;
		}
		reverse(code[id].begin(), code[id].end());
	}
	
	if (ok)
	{
		printf("YES\n");
		for (i = 1; i <= n; i++)
		{
			printf("%s\n", code[i].c_str());
		}
	}
	else
	{
		printf("NO\n");
	}
	
	return 0;
}