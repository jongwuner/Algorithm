#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef pair<int, int> Pair;
const int INF = 123456789;
int N, M, S;
vector<int> dist;
vector<bool> visit;
vector< vector<Pair>> adj;
priority_queue<Pair, vector<Pair>, greater<Pair>> PQ;
int main() {
	scanf("%d%d", &N, &M);
	dist.resize(N + 1, INF);
	visit.resize(N + 1, false);
	adj.resize(N + 1);
	for (int i = 0, a, b, c; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({b, c});
	}
	scanf("%d", &S);
	dist[S] = 0;
	PQ.push({0, S});
	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visit[curr]);
		if (visit[curr]) break;

		visit[curr] = true;
		for (Pair next : adj[curr]) {
			int nextNode = next.first;
			int nextVal = next.second;
			if (dist[nextNode] > dist[curr] + nextVal) {
				dist[nextNode] = dist[curr] + nextVal;
				PQ.push({dist[nextNode], nextNode});
			}
		}
	}

	printf("시작점 : [ %d ]번 노드\n", S);
	for (int i = 1; i <= N; i++) {
		printf("[ %d -> %d ] = %d\n", S, i, dist[i]);
	}
	return 0;
}