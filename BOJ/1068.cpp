#include<cstdio>
int p[50], a, c[50];
int main()
{
	int n, d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", p + i);
		if (p[i] >= 0)c[p[i]]++;
	}
	scanf("%d", &d);
	c[p[d]]--;
	for (int i = 0; i < n; i++)
	{
		if (c[i]) continue;
		int j = i;
		while (j != -1)
		{
			if (j == d) break;
			j = p[j];
		}
		a += j == -1;
	}
	printf("%d\n", a);
	return 0;
}