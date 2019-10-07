#include<iostream>
#include<vector>
#include<cstring>
#define MAX 550
using namespace std;
int N, M, T, pre[MAX], edgeCnt;
bool visit[MAX];
vector<int> adj[MAX];
int DFS(int idx) {
	int cnt = 0;
	visit[idx] = true;
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (!visit[next]) {
			cnt += DFS(next);
		}
	}
	edgeCnt += adj[idx].size();
	return cnt + 1;
}
int main() {
	while (scanf("%d %d", &N, &M), (N || M)) {
		int cnt = 0;

		memset(visit, false, sizeof(visit));
		memset(pre, -1, sizeof(pre));
		for (int i = 0; i < MAX; i++) adj[i].clear();

		for (int i = 1, a, b; i <= M; i++) {
			scanf("%d %d", &a, &b);
			adj[a].push_back(b); adj[b].push_back(a);
		}

		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				edgeCnt = 0;
				if (DFS(i) - 1 == edgeCnt / 2) {
					cnt++;
				}
			}
		}

		T++;

		if (cnt == 0)
			printf("Case %d: No trees.\n", T);
		else if (cnt == 1)
			printf("Case %d: There is one tree.\n", T);
		else if (cnt >= 2)
			printf("Case %d: A forest of %d trees.\n", T, cnt);
	}
	return 0;
}