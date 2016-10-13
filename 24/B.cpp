#include <cstdio>
#include <string>
#include <map>

using namespace std;

const int N = 51;

int POINTS[N] = {0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

struct Record
{
	int count[N];
	int points;
};

bool cmp1(const Record &r1, const Record &r2)
{
	if (r1.points != r2.points)
	{
		return r1.points > r2.points;
	}
	
	for (int i = 1; i <= 50; i++)
	{
		if (r1.count[i] != r2.count[i])
		{
			return r1.count[i] > r2.count[i];
		}
	}
	
	return false;
}

bool cmp2(const Record &r1, const Record &r2)
{
	if (r1.count[1] != r2.count[1])
	{
		return r1.count[1] > r2.count[1];
	}
	
	if (r1.points != r2.points)
	{
		return r1.points > r2.points;
	}
	
	for (int i = 2; i <= 50; i++)
	{
		if (r1.count[i] != r2.count[i])
		{
			return r1.count[i] > r2.count[i];
		}
	}
	
	return false;
}


map<string, Record> data;

void champion1()
{
	map<string, Record>::iterator iter, bestIter;
	bestIter = iter = data.begin();
	
	for (iter++; iter != data.end(); iter++)
	{
		if (cmp1(iter->second, bestIter->second))
		{
			bestIter = iter;
		}
	}
	
	printf("%s\n", bestIter->first.c_str());
}

void champion2()
{
	map<string, Record>::iterator iter, bestIter;
	bestIter = iter = data.begin();
	
	for (iter++; iter != data.end(); iter++)
	{
		if (cmp2(iter->second, bestIter->second))
		{
			bestIter = iter;
		}
	}
	
	printf("%s\n", bestIter->first.c_str());
}

int main()
{
	int t, n, i, j;
	char str[55];
	string name;
	
	
	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for (j = 1; j <= n ; j++)
		{
			scanf("%s", str);
			name = str;
			data[name].count[j]++;
			data[name].points += POINTS[j];
		}
	}
	
	champion1();
	champion2();
	
	return 0;
}