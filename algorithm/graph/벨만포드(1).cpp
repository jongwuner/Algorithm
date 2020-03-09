#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> Pair;
const int INF = 123456789;
int N, M, S;
vector<int> dist;
vector< vector<Pair> > adj;
int main() {
	scanf("%d%d", &N, &M);
	dist.resize(N + 1, INF);
	adj.resize(N + 1);
	for (int i = 0, a, b, c; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b, c });
	}

	scanf("%d", &S);
	dist[S] = 0;
	bool minusCycle = false;
	
	for (int edge = 1; edge <= N; edge++) {
		for (int curr = 1; curr <= N; curr++) {
			for (Pair next : adj[curr]) {
				int nextNode = next.first;
				int nextVal = next.second;
				if (dist[curr] != INF && dist[nextNode] > dist[curr] + nextVal) {
					dist[nextNode] = dist[curr] + nextVal;
					if (edge == N) minusCycle = true;
				}
			}
		}
	}
	if (minusCycle) printf("음수사이클이 존재해서 최단경로를 구할 수 없음.\n");
	else {
		printf("시작점 : [ %d ]\n", S);
		for (int i = 1; i <= N; i++) {
			printf("[ %d -> %d ] = %d\n", S, i, dist[i]);
		}
	}
	return 0;
}

--------------------
6 5

1 2 3
1 3 10
3 5 2
2 5 5
2 4 7

1
--------------------

6 6

1 2 3
1 3 10
3 5 2
2 5 5
2 4 7
5 6 -10

1



6 8

1 2 3
1 3 10
3 5 2
2 5 5
2 4 7
5 6 -10
6 4 -15
4 5 -30

1
