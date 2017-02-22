/*
[����]
N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

[�Է�]
ù° �ٿ� �ڿ��� N(1��N��100,000)�� �־�����. ���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����. ���� �ٿ��� M(1��M��100,000)�� �־�����. ���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�. ��� �������� ������ int �� �Ѵ�.

[���]
M���� �ٿ� ���� ����Ѵ�. �����ϸ� 1��, �������� ������ 0�� ����Ѵ�.



[�ڸ�Ʈ]
Binary Search ������.
BS�� �����ϴ� �� ���� edge case�� ����� ��Ƴ��� ���� �ð� �ʰ��� ������.
üũ�� �κ��� Ȯ���ϰ� �� �� �ֵ��� ������ �����ؾ��Ѵ�.

�ٸ� ���� PS���� BSearch�� �ʿ��ϸ� Algorithm header�� �ִ� binary_search(begin,end,key)�� �� �� �ִ�.
*/
#include <stdio.h>
#include <string>

#define getchar_unlocked() getchar()
#define putchar_unlocked(x) putchar(x);

using namespace std;


inline void getInt(int &n) {
	n = 0;
	char ch = getchar_unlocked(); char sign = 1;
	while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getchar_unlocked(); }
	while (ch >= '0' && ch <= '9')
		n = /*n*10*/(n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked();
	n = n*sign;
}

#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int N, M;
int a[100000];
char out[300000];
int search(int n)
{
	int p = N / 2;
	int st = 0, end = N;
	while (st < end)
	{
		if (a[p] == n)
		{
			return p;
		}
		if (a[p] > n)
		{
			end = p;
			p = (st + p) / 2;
			continue;
		}
		if (a[p] < n)
		{
			st = p + 1;
			p = (st + end)/ 2;
			continue;
		}
	}
	return -1;
}


int main()
{
	getInt(N);
	for (int i = 0; i < N; i++) 
	{
		getInt(a[i]);
	}
	sort(a, a + N);
	getInt(M);
	int mini = a[0], big = a[N - 1];
	int s;
	for (int i = 0; i < M; i++)
	{
		getInt(s);
		if (s < mini || s > big)
		{
			out[i*2] = '0';
			out[i * 2 + 1] = '\n';
			continue;
		}

		//binary_search(a, a + N, 0);

		if (search(s) < 0)
		{
			out[i * 2] = '0';
			out[i * 2 + 1] = '\n';
		}
		else
		{
			out[i * 2] = '1';
			out[i * 2 + 1] = '\n';
		}
	}
	printf("%s", out);

	return 0;

}