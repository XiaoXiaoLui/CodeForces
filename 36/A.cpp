#include <cstdio>

const int N = 105;
char s[N];

int main()
{
	int n, i, last, interval;
	char ch;
	bool ans = true;
	
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	
	fscanf(in, "%d", &n);
	
	fscanf(in, "%s", s);
	
	for (i = 0; s[i] != '1'; i++);
	last = i;
	for (i = last + 1; s[i] != '1'; i++);
	interval = i - last;
	
	last = i;
	for (i = i + 1; i < n; i++)
	{
		if (s[i] == '1')
		{
			if (i - last != interval)
			{
				ans = false;
				break;
			}
			
			last = i;
		}
	}
	
	if (ans)
	{
		fprintf(out, "YES\n");
	}
	else
	{
		fprintf(out, "NO\n");
	}
	
	return 0;
};