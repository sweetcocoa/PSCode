/*

1260.  DFS와 BFS

[입력] 첫째 줄에 정점의 개수 N(1≤N≤1,000), 간선의 개수 M(1≤M≤10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 한 간선이 여러 번 주어질 수도 있는데, 
간선이 하나만 있는 것으로 생각하면 된다. 입력으로 주어지는 간선은 양방향이다.

[출력] 첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. 
V부터 방문된 점을 순서대로 출력하면 된다.

DFS를 재귀적으로 구현하는 방법과 그렇지 않은 방법이 있는데, 나는 비 재귀적으로 구현함.
DFS 부분의 visitied를 체크하는 if는 그냥 단지 !visited[i] 로 해도 되고 그게 더 빠르지만, 
코드의 재사용 + 가독성을 위해 남겨둔다. 

[문제점] 근데 최단수행시간 코드는 DFS를 재귀적으로 구성했는데 0MS가 나오는데, 
나는 DFS를 루프로 구성했는데도 수행시간이 0MS대에서 끊기지 않는 것을 보니 코드가 전체적으로 느린 듯. 왜 느릴까?

가설 
1. STL이 느림 : 정렬 후 순회를 위해 set을 사용했는데 adj edge를 읽을때 set 말고 sort된 vector를 사용하는 편이 더 빠를 것 같다.


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