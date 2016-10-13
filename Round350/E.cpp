#include <iostream>
#include <list>

using namespace std;

#define N 500002

char seq[N];
char oper[N];

list<char> lst;

void printlst()
{
	list<char>::iterator iter;
	for (iter = lst.begin(); iter != lst.end(); iter++)
	{
		cout << *iter;
	}
	cout << endl;
}

int main()
{
	int n, m, p, i;
	
	
	cin >> n >> m >> p;
	p--;
	
	cin >> seq;
	cin >> oper;
	
	for (i = 0; i < n; i++)
	{
		lst.push_back(seq[i]);
	}
	
	list<char>::iterator iter;
	list<char>::iterator iter2;
	for (iter = lst.begin(), i = 0; i != p; ++iter, ++i);
	
	int count;
	for (i = 0; i < m; i++)
	{
		count = 0;
		switch (oper[i])
		{
		case 'L':
			--iter;
			break;
		case 'R':
			++iter;
			break;
		case 'D':
			if ((*iter) == '(')
			{
				iter2 = iter;
				iter2++;
				for (count = 1; count != 0; ++iter2)
				{
					if ((*iter2) == '(')
					{
						count++;
					}
					else
					{
						count--;
					}
					
					if (count == 0)
					{
						break;
					}
				}
				iter2++;
				iter = lst.erase(iter, iter2);
				if (iter == lst.end())
				{
					--iter;
				}
			}
			else
			{
				iter2 = iter;
				iter2--;
				for (count = 1; count != 0; --iter2)
				{
					if ((*iter2) == '(')
					{
						count--;
					}
					else
					{
						count++;
					}
					
					if (count == 0)
					{
						break;
					}
				}
				
				iter++;
				iter = lst.erase(iter2, iter);
				if (iter == lst.end())
				{
					--iter;
				}
			}
			break;
		}
		//printlst();
	}
	
	printlst();
	
	
	return 0;
}