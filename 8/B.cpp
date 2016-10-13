#include <iostream>
#include <set>

using namespace std;

#define N 102

struct Position
{
	int x;
	int y;
	Position(){}
	Position(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	
	bool operator < (const Position &other) const
	{
		if (x < other.x)
		{
			return true;
		}
		
		else if (x == other.x && y < other.y)
		{
			return true;
		}
		
		return false;
	}
};

void coverAround(set<Position> &pointSet, const Position &pos)
{	
	pointSet.insert(Position(pos.x - 1, pos.y));
	pointSet.insert(Position(pos.x + 1, pos.y));
	pointSet.insert(Position(pos.x, pos.y + 1));
	pointSet.insert(Position(pos.x, pos.y - 1));
	
}

int main()
{
	char path[N];
	set<Position> pointSet;
	int i = 0;
	Position pos(0, 0);
	Position lastPos(0, 0);
	bool bOK = true;
	
	cin >> path;
	pointSet.insert(pos);
	for (i = 0; path[i]; i++)
	{
		switch (path[i])
		{
		case 'L':
			pos.x--;
			break;
		case 'U':
			pos.y++;
			break;
		case 'R':
			pos.x++;
			break;
		case 'D':
			pos.y--;
			break;
		}
		
		if (pointSet.count(pos) > 0)
		{
			bOK = false;
			break;
		}
		else
		{
			pointSet.insert(pos);
			coverAround(pointSet, lastPos);
			lastPos = pos;
		}
	}
	
	if (bOK)
	{
		cout << "OK" << endl;
	}
	else
	{
		cout << "BUG" << endl;
	}
	
	return 0;
}