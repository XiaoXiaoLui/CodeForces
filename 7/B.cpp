#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;


#define N 120

struct Block
{
	int id;
	int start;
	int len;
	Block() : id(0), start(0), len(0){}
	Block(int id, int start, int len)
	{
		this->id = id;
		this->start = start;
		this->len = len;
	}
	Block(const Block &other)
	{
		id = other.id;
		start = other.start;
		len = other.len;
	}
	
	bool operator < (const Block &other) const
	{
		return start < other.start;
	}
	
	Block& operator = (const Block &other)
	{
		id = other.id;
		start = other.start;
		len = other.len;
		
		return *this;
	}
};


int a[N];
int id = 1;
map<int, Block> blocks;
Block b[N];
int m = 0;

int alloc(int n)
{
	int i = 1;
	int j = 1;
	
	while (i <= m - n + 1)
	{
		if (a[i])
		{
			i++;
		}
		else
		{
			for (j = i; j <= m && j - i + 1 <= n && !a[j]; j++);
			
			// find a block
			if (j - i + 1 > n)
			{
				break;
			}
			i = j + 1;
		}
	}
	
	if (i <= m - n + 1)
	{
		//blocks[id] = Block(id, i, j - i);
		pair<int, Block> p = pair<int, Block>(id, Block(id, i, j - i));
		blocks.insert(p);
		
		for (; i < j; i++)
		{
			a[i] = 1;
		}
		
		return id++;
	}
	else
	{
		return 0;
	}
}

int erase(int i)
{
	if (blocks.count(i) > 0)
	{
		for (int k = blocks[i].start; k < blocks[i].start + blocks[i].len; k++)
		{
			a[k] = 0;
		}
		
		blocks.erase(i);
		return 1;
	}
	else
	{
		return 0;
	}
}

void defragment()
{
	map<int, Block>::iterator iter;
	int i = 0;
	for (iter = blocks.begin(); iter != blocks.end(); iter++)
	{
		b[i].start = (*iter).second.start;
		b[i].len = (*iter).second.len;
		b[i].id = (*iter).second.id;
		
		i++;
	}
	sort(b, b + i);
	
	int num = i;
	int tail = 1;
	for (i = 0; i < num; i++)
	{
		b[i].start = tail;
		tail += b[i].len;
	}
	
	// update a[]
	memset(a, 0, sizeof(a));
	tail = 1;
	blocks.clear();
	for (i = 0; i < num; i++)
	{
		for (int j = b[i].start; j < b[i].start + b[i].len; j++)
		{
			a[j] = 1;
		}
		blocks.insert(pair<int, Block>(b[i].id, b[i]));
	}
	
	
}

int main()
{
	int t;
	string oper;
	int num;
	int result;
	
	
	memset(a, 0, sizeof(a));
	cin >> t >> m;
	
	for (int i = 0; i < t; i++)
	{
		cin >> oper;
		
		if (oper == "alloc")
		{
			cin >> num;
			result = alloc(num);
			
			if (result > 0)
			{
				cout << result << endl;
			}
			else
			{
				cout << "NULL" << endl;
			}
		}
		else if (oper == "erase")
		{
			cin >> num;
			result = erase(num);
			if (!result)
			{
				cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
			}
		}
		else
		{
			defragment();
		}
	}
	
	return 0;
}