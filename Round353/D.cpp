#include <iostream>
#include <set>
#include <climits>

using namespace std;




const int N = 100005;
int parent[N];
int n;

int main()
{
	int i, n, value;
	set<pair<int, int> > st;
	
	cin >> n;
	set<pair<int, int> >::iterator iter1, iter2;
	st.insert(make_pair(0, 0));
	st.insert(make_pair(INT_MAX, 0));
	
	for (i = 1; i <= n; i++)
	{
		cin >> value;
		if (i >= 2)
		{
			iter2 = st.upper_bound(make_pair(value, 0));
			iter1 = iter2;
			iter1--;
			
			if ((*iter1).second > (*iter2).second)
			{
				parent[i] = (*iter1).first;
			}
			else
			{
				parent[i] = (*iter2).first;
			}
		}
		st.insert(make_pair(value, i));
	}
	
	
	for (i = 2; i <= n; i++)
	{
		cout << parent[i] << " ";
	}
	cout << endl;
	
	
	return 0;
}