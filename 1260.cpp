/*

1260.  DFS�� BFS

[�Է�] ù° �ٿ� ������ ���� N(1��N��1,000), ������ ���� M(1��M��10,000), Ž���� ������ ������ ��ȣ V�� �־�����. 
���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����. �� ������ ���� �� �־��� ���� �ִµ�, 
������ �ϳ��� �ִ� ������ �����ϸ� �ȴ�. �Է����� �־����� ������ ������̴�.

[���] ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. 
V���� �湮�� ���� ������� ����ϸ� �ȴ�.

DFS�� ��������� �����ϴ� ����� �׷��� ���� ����� �ִµ�, ���� �� ��������� ������.
DFS �κ��� visitied�� üũ�ϴ� if�� �׳� ���� !visited[i] �� �ص� �ǰ� �װ� �� ��������, 
�ڵ��� ���� + �������� ���� ���ܵд�. 

[������] �ٵ� �ִܼ���ð� �ڵ�� DFS�� ��������� �����ߴµ� 0MS�� �����µ�, 
���� DFS�� ������ �����ߴµ��� ����ð��� 0MS�뿡�� ������ �ʴ� ���� ���� �ڵ尡 ��ü������ ���� ��. �� ������?

���� 
1. STL�� ���� : ���� �� ��ȸ�� ���� set�� ����ߴµ� adj edge�� ������ set ���� sort�� vector�� ����ϴ� ���� �� ���� �� ����.


*/

#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;
set<int> adj[1001];
stack<int> st;
queue<int> q;
int visited[1001];

#define STACKPOP 2
#define STACKED 3
#define QUEUEPOP 4

int main()
{
	int N, M, V;
	int u, v;
	scanf("%d%d%d", &N, &M, &V);
	for (int i = 1; i <= M; ++i)
	{
		scanf("%d%d", &u, &v);
		adj[u].insert(v);
		adj[v].insert(u);
	}

	//DFS
	st.push(V);
	while (!st.empty())
	{
		int u = st.top();
		int contin = 0;
		if (visited[u] != STACKED && visited[u] != STACKPOP)
		{
			visited[u] = STACKED;
			printf("%d ", u);
		}
		for (auto &e : adj[u])
		{
			if (visited[e] != STACKPOP && visited[e] != STACKED)
			{
				st.push(e);
				contin = 1;
				break;
			}
		}
		if (!contin) // nowhere to go
		{
			st.pop();
			visited[u] = STACKPOP;
		}
	}
	printf("\n");
	
	//BFS
	q.push(V);
	while (!q.empty())
	{
		int u = q.front(); q.pop();

		if (visited[u] == QUEUEPOP)
		{
			continue;
		}
		visited[u] = QUEUEPOP;
		printf("%d ", u);
		for (auto &e : adj[u])
		{
			if (visited[e] != QUEUEPOP)
			{
				q.push(e);
			}
		}
	}
	printf("\n");
}