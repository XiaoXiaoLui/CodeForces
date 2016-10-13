#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define mp make_pair<int, int>
#define pii pair<int, int>

const int N = 1e5 + 10;
const int M = 350;

struct Block
{
	Block() : maxValue(0), left(0), right(0)
	{
	}
	
	vector<pii> vec;
	int maxValue;
	
	Block *left;
	Block *right;
};

struct BlockList
{
	BlockList() : top(0)
	{
		head = newBlock();
		tail = newBlock();
		
		Block *first = newBlock();
		
		head->left = 0;
		head->right = first;
		first->left = head;
		first->right = tail;
		tail->left = first;
		tail->right = 0;
	}
	
	Block *newBlock()
	{
		return &MEM[top++];
	}
	
	void insert(pii a, int c)
	{
		Block *pBlock = tail->left;
		while (1)
		{
			if (pBlock->left != head && c > pBlock->vec.size() && a.first > pBlock->maxValue)
			{
				c -= pBlock->vec.size();
				pBlock = pBlock->left;
			}
			else
			{
				vector<pii>::reverse_iterator iter;
				for (iter = pBlock->vec.rbegin(); iter != pBlock->vec.rend() && c > 0 && iter->first < a.first; iter++, c--);
				pBlock->vec.insert(iter.base(), a);
				pBlock->maxValue = max(pBlock->maxValue, a.first);
				break;
			}
		}
		if (pBlock->vec.size() > 2*M)
		{
			split(pBlock);
		}
	}
	
	void split(Block *p)
	{
		Block *tmp = newBlock();
		int i;
		for (i = M; i < p->vec.size(); i++)
		{
			tmp->vec.push_back(p->vec[i]);
			tmp->maxValue = max(tmp->maxValue, p->vec[i].first);
		}
		p->vec.resize(p->vec.size() - tmp->vec.size());
		for (i = 0; i < p->vec.size(); i++)
		{
			p->maxValue = max(p->maxValue, p->vec[i].first);
		}
		
		tmp->left = p;
		tmp->right = p->right;
		p->right = tmp;
		tmp->right->left = tmp;
	}
	
	void output()
	{
		Block *p = head->right;
		int i;
		while (p != tail)
		{
			for (i = 0; i < p->vec.size(); i++)
			{
				printf("%d ", p->vec[i].second);
			}
			p = p->right;
		}
		printf("\n");
	}
	

	Block MEM[2*M];
	int top;
	
	Block *head;
	Block *tail;
} lst;


int main()
{
	int n, i, a, c;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &c);
		lst.insert(mp(a, i), c);
	}
	
	lst.output();
	
	return 0;
}