#include<stdio.h>
int main()
{
	int N; scanf("%d", &N);
	int cnt = 0;
	for (int n = 1; n <= N; n++)
	{
		if (n < 100) {
			cnt++; continue;
		}
		if (n / 100 - (n % 100) / 10 == (n % 100) / 10 - n % 10)
		{
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}