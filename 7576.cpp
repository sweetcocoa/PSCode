/*
[문제]
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.

창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

[입력]
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N 은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

[출력]
여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.



흔한 BFS 문제.

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