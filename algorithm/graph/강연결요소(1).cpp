#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int N, M, nowTime, sccCnt;
stack<int> St;
vector<int> dfsn, sccNum;
vector<bool> finished;
vector< vector<int>> adj, SCC;
int DFS(int curr) {
	int result = dfsn[curr] = ++nowTime;

	St.push(curr);
	for (int next : adj[curr]) {
		if (dfsn[next] == 0) {
			result = min(result, DFS(next));
		}
		else if (!finished[next]) {
			result = min(result, dfsn[next]);
		}
	}

	if (result == dfsn[curr]) {
		vector<int> thisSCC;
		while (1) {
			int nodeNum = St.top();
			St.pop();

			thisSCC.push_back(nodeNum);
			finished[nodeNum] = true;
			sccNum[nodeNum] = sccCnt;

			if (nodeNum == curr) break;
		}
		sccCnt++;
		sort(thisSCC.begin(), thisSCC.end());
		SCC.push_back(thisSCC);
	}
	return result;
}
int main() {
	scanf("%d%d", &N, &M);
	adj.resize(N + 1);
	finished.resize(N + 1);
	sccNum.resize(N + 1);
	dfsn.resize(N + 1);

	for (int i = 1, a, b; i <= M; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}
	
	for (int i = 1; i <= N; i++) {
		if (dfsn[i] == 0) DFS(i);
	}

	printf("%d\n", sccCnt);
	sort(SCC.begin(), SCC.end());
	for (int i = 0; i < SCC.size(); i++) {
		for (int curr : SCC[i]) {
			printf("%d ", curr);
		}
		printf("-1\n");
	}
	return 0;
}



---------------------
12 15
1 2
2 3
3 4
4 2
1 4
4 5
5 6
6 8
6 7
8 9
9 10
10 6
7 11
11 12
12 5