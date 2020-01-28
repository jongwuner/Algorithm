#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
queue<int> Q;
vector<int> indegree;
vector<int> ans;
vector< vector<int> > adj;
int main() {
	scanf("%d%d", &N, &M);
	adj.resize(N + 1);
	indegree.resize(N + 1);

	for (int i = 1, a, b; i <= M; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) Q.push(i);
	}

	for (int i = 1; i <= N; i++) {
		int curr = Q.front();
		Q.pop();

		ans.push_back(curr);
		for (int next : adj[curr]) {
			if (--indegree[next] == 0)
				Q.push(next);
		}
	}
	for (int curr : ans) {
		printf(" %d", curr);
	}
	return 0;
}


6 5
1 6
1 4
2 4
3 4
5 6