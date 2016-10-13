#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;
};

Point p[3];



bool isRight(const Point &p1, const Point &p2, const Point p3)
{
	if (p1.x == p2.x && p1.y == p2.y || p1.x == p3.x && p1.y == p3.y)
	{
		return false;
	}
	return (p2.y - p1.y) * (p3.y - p1.y) + (p2.x - p1.x) * (p3.x - p1.x) == 0;
}

bool right()
{
	bool ret = false;
	for (int i = 0; i < 3; i++)
	{
		if (isRight(p[i], p[(i + 1)%3], p[(i + 2) % 3]))
		{
			ret = true;
			break;
		}
	}
	
	return ret;
}

int main()
{
	int i;
	
	for (i = 0; i < 3; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	
	int ans = 0;
	
	ans = right() ? 1 : 0;
	
	if (!ans)
	{
		for (i = 0; i < 3; i++)
		{
			p[i].x++;
			if (right())
			{
				ans = 2;
				break;
			}
			p[i].x--;
			
			p[i].x--;
			if (right())
			{
				ans = 2;
				break;
			}
			p[i].x++;
			
			p[i].y++;
			if (right())
			{
				ans = 2;
				break;
			}
			p[i].y--;
			
			p[i].y--;
			if (right())
			{
				ans = 2;
				break;
			}
			p[i].y++;
			
			
		}
	}
	

	switch (ans)
	{
	case 0:
		cout << "NEITHER" << endl;
		break;
	case 1:
		cout << "RIGHT" << endl;
		break;
	case 2:
		cout << "ALMOST" << endl;
		break;
	}
	
	return 0;
}