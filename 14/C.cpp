#include <iostream>
#include <climits>

using namespace std;

struct Segment
{
	int x1;
	int y1;
	int x2;
	int y2;
};

int main()
{
	int left, right, up, down;
	Segment v[4], h[4];
	int vlen = 0, hlen = 0;

	
	Segment tmp;
	bool ok = true;
	for (int i = 0; i < 4; i++)
	{
		cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
		
		if (tmp.x1 == tmp.x2)	// vertical
		{
			if (tmp.y1 == tmp.y2)
			{
				ok = false;
				break;
			}
			
			v[vlen++] = tmp;
		}
		else if (tmp.y1 == tmp.y2) // horizontal
		{
			if (tmp.x1 == tmp.x2)
			{
				ok = false;
				break;
			}
			h[hlen++] = tmp;
		}
		else
		{
			ok = false;
			break;
		}
	}
	
	if (ok)
	{
		if (vlen == 2 && hlen == 2)
		{
			left = min(v[0].x1, v[1].x1);
			right = max(v[0].x1, v[1].x1);
			up = min(h[0].y1, h[1].y1);
			down = max(h[0].y1, h[1].y1);
			
			if (up != min(v[0].y1, v[0].y2) || down != max(v[0].y1, v[0].y2))
			{
				ok = false;
			}
			if (up != min(v[1].y1, v[1].y2) || down != max(v[1].y1, v[1].y2))
			{
				ok = false;
			}
			if (left != min(h[0].x1, h[0].x2) || right != max(h[0].x1, h[0].x2))
			{
				ok = false;
			}
			if (left != min(h[1].x1, h[1].x2) || right != max(h[1].x1, h[1].x2))
			{
				ok = false;
			}
		}
		else
		{
			ok = false;
		}
	}
	
	if (ok)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}