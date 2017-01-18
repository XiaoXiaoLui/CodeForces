#include<bits/stdc++.h>

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

const int N = 1e6 + 100;

vector<string> ans[N];
int maxDeep = 0;
string line;
int pos = 0;

size_t getNextPos()
{
	size_t res = line.find(',', pos);
	if (res == string::npos)
	{
		res = line.size();
	}
	return res;
}

string read()
{
	size_t nextPos = getNextPos();
	string s;
	s = line.substr(pos, nextPos - pos);
	pos = nextPos + 1;
	return s;
}

void dfs(int cnt, int deep)
{
	int num;
	string s;
	maxDeep = max(maxDeep, deep);
	while (cnt--)
	{
		s = read();
		ans[deep].push_back(s);
		s = read();
		num = atoi(s.c_str());
		
		if (num > 0)
		{
			dfs(num, deep + 1);
		}
	}
}

int main()
{
	USE_IOSTREAM;
	//freopen("1.txt", "r", stdin);
	int num;
	string s;
	
	int deep = 0;
	cin >> line;
	pos = 0;
	while (pos < line.size())
	{
		s = read();
		ans[0].push_back(s);
		
		s = read();
		num = atoi(s.c_str());
		if (num > 0)
		{
			dfs(num, deep + 1);
		}
	}
	
	cout << maxDeep + 1 << endl;
	for (int i = 0; i <= maxDeep; i++)
	{
		for (auto &tmp : ans[i])
		{
			cout << tmp << " ";
		}
		cout << endl;
	}
	
	return 0;
}