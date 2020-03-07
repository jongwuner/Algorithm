#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
typedef pair<int, int> Pair;
int V, E, now, bccCnt;
stack<Pair> St;
vector<int> dfsn;
vector< vector<int> > adj;
vector< vector<Pair> > BCC;
int DFS(int curr, int prev = -1) {
	int res;
	res = dfsn[curr] = ++now;

	for (int next : adj[curr]) {
		if (next == prev) continue;
		if (dfsn[curr] > dfsn[next]) St.push({curr, next});
		if (dfsn[next] > 0) res = min(res, dfsn[next]);
		else {
			int tmp = DFS(next, curr);
			res = min(res, tmp);

			if (tmp >= dfsn[curr]) {
				vector<Pair> currBCC;
				while (!St.empty() && St.top() != Pair(curr, next)) {
					currBCC.push_back(St.top());
					St.pop();
				}
				currBCC.push_back(St.top());
				St.pop();
				BCC.push_back(currBCC);
				bccCnt++;
			}
		}
	}

}
int main() {
	// 그래프 입력받기
	scanf("%d %d", &V, &E);
	adj.resize(V + 1);
	dfsn.resize(V + 1);
	for (int i = 0; i < E; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < V; ++i)
		if (dfsn[i] == 0) DFS(i);
}
