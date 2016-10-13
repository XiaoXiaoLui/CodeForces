#include <cstdio>
#include <queue>

//#define LDD "%ll" "d"
#define LDD "%I64d"

using namespace std;
typedef long long ll;

#define mp make_pair<ll, int>
#define pi pair<ll, int>

const int N = 50005;
char seq[N];
priority_queue<pi> Q;

int main()
{
	int i;
	int a,  b;
	scanf("%s", seq);
	
	ll c = 0, ans = 0;
	pi tmp;
	for (i = 0; seq[i]; i++)
	{
		if (seq[i] == '(')
		{
			c++;
		}
		else if (seq[i] == ')')
		{
			c--;
		}
		else
		{
			seq[i] = ')';
			c--;
			scanf("%d%d", &a, &b);
			
			ans += b;
			Q.push(mp(b - a, i));
		}
		
		if (c < 0)
		{
			if (Q.empty())
			{
				break;
			}
			
			tmp = Q.top();
			Q.pop();
			ans -= tmp.first;
			seq[tmp.second] = '(';
			
			c += 2;
		}
	}
	
	if (c != 0)
	{
		printf("-1\n");
	}
	else
	{
		printf(LDD "\n%s\n", ans, seq);
	}
	
	return 0;
}