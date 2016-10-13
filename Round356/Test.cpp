#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
ll c[100005];



int main()
{
	
	int  i;
	ll m;
    for (i = 1; i <= 10000; i++)
	{
		c[i] = (ll) i * i * i;
	}
    
    scanf("%lld", &m);

    ll sum = 0;
	int cur = 1;
    vector<ll> vec;
    while(sum <= m)
    {
        while(sum + c[cur] >= c[cur+1])
        {
            cur++;
            if(sum + c[cur] > m) break;
        }
        if(sum + c[cur] > m) break;
        vec.push_back(cur);
        sum += c[cur];
    }
	
	for (i = 0; i < vec.size(); i++)
	{
		printf("%d ", vec[i]);
	}
	
	printf("\n%lld\n", sum);
	return 0;
}