/*
[����]
ö���� �丶�� ���忡���� �丶�並 �����ϴ� ū â���� ������ �ִ�. �丶��� �Ʒ��� �׸��� ���� ���� ��� ������ ĭ�� �ϳ��� �־ â���� �����Ѵ�.

â���� �����Ǵ� �丶��� �߿��� �� ���� �͵� ������, ���� ���� ���� �丶��鵵 ���� �� �ִ�. ���� �� �Ϸ簡 ������, ���� �丶����� ������ ���� �ִ� ���� ���� �丶����� ���� �丶���� ������ �޾� �Ͱ� �ȴ�. �ϳ��� �丶���� ������ ���� ����, ������, ��, �� �� ���⿡ �ִ� �丶�並 �ǹ��Ѵ�. �밢�� ���⿡ �ִ� �丶��鿡�Դ� ������ ���� ���ϸ�, �丶�䰡 ȥ�� ������ �ʹ� ���� ���ٰ� �����Ѵ�. ö���� â���� ������ �丶����� ��ĥ�� ������ �� �Ͱ� �Ǵ���, �� �ּ� �ϼ��� �˰� �;� �Ѵ�.

�丶�並 â���� �����ϴ� ���ڸ���� ���ڵ��� ũ��� ���� �丶���� ���� ���� �丶����� ������ �־����� ��, ��ĥ�� ������ �丶����� ��� �ʹ���, �� �ּ� �ϼ��� ���ϴ� ���α׷��� �ۼ��϶�. ��, ������ �Ϻ� ĭ���� �丶�䰡 ������� ���� ���� �ִ�.

[�Է�]
ù �ٿ��� ������ ũ�⸦ ��Ÿ���� �� ���� M,N�� �־�����. M�� ������ ���� ĭ�� ��, N �� ������ ���� ĭ�� ���� ��Ÿ����. ��, 2 �� M,N �� 1,000 �̴�. ��° �ٺ��ʹ� �ϳ��� ���ڿ� ����� �丶����� ������ �־�����. ��, ��° �ٺ��� N���� �ٿ��� ���ڿ� ��� �丶���� ������ �־�����. �ϳ��� �ٿ��� ���� �����ٿ� ����ִ� �丶���� ���°� M���� ������ �־�����. ���� 1�� ���� �丶��, ���� 0�� ���� ���� �丶��, ���� -1�� �丶�䰡 ������� ���� ĭ�� ��Ÿ����.

[���]
�������� �丶�䰡 ��� ���� �������� �ּ� ��¥�� ����ؾ� �Ѵ�. ����, ����� ������ ��� �丶�䰡 �;��ִ� �����̸� 0�� ����ؾ� �ϰ�, �丶�䰡 ��� ������ ���ϴ� ��Ȳ�̸� -1�� ����ؾ� �Ѵ�.



���� BFS ����.

*/
#include<stdio.h>
#include<vector>
#include<queue>
//#include<utility>
using namespace std;
int tomato[1001][1001];
typedef struct Point
{
	int i, j, day;
}Point;
queue<Point> nextDay;
int day;
int numMuture;
int numVoid;
int N, M;
void inline t_emplace(int i, int j, int day)
{
	tomato[i][j] = 1;
	nextDay.push({ i,j,day });
	numMuture++;
}
int main()
{
	scanf("%d%d", &M, &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; ++j)
		{
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1)
			{
				nextDay.push({ i,j,day });
				numMuture++;
			}
			else if (tomato[i][j] == -1)
			{
				numVoid++;
			}
		}
	}

	if (nextDay.size() == N*M - numVoid)
	{
		printf("0\n");
		return 0;
	}
	while (!nextDay.empty())
	{
		Point point = nextDay.front(); nextDay.pop();
		int i = point.i; int j = point.j; day = point.day;
		if (j < M)
		{
			if (0 == tomato[i][j + 1])
			{
				t_emplace(i, j + 1, day+1);
			}
		}
		if (j > 1)
		{
			if (0 == tomato[i][j - 1])
			{
				t_emplace(i, j - 1, day+1);
			}
		}
		if (i > 1)
		{
			if (0 == tomato[i - 1][j] )
			{
				t_emplace(i - 1, j, day+1);
			}
		}
		if (i < N)
		{
			if (0 == tomato[i + 1][j])
			{
				t_emplace(i + 1, j,day+1);
			}
		}
	}
	
	if (numMuture == N*M - numVoid)
	{
		printf("%d\n", day);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}