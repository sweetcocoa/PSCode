/*
[문제]
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

[입력]
첫째 줄에 자연수 N(1≤N≤100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1≤M≤100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수들의 범위는 int 로 한다.

[출력]
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.



[코멘트]
Binary Search 문제다.
BS를 구현하는 데 역시 edge case를 제대로 잡아내지 못해 시간 초과가 떴었다.
체크한 부분을 확실하게 뺄 수 있도록 범위를 설정해야한다.

다만 실제 PS에서 BSearch가 필요하면 Algorithm header에 있는 binary_search(begin,end,key)를 쓸 수 있다.
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