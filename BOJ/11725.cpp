#include<iostream>
#include<vector>
#define MAX 100005
using namespace std;
vector<int> adj[MAX];
bool visit[MAX];
int parent[MAX], N, a, b;
void go(int idx) {
	visit[idx] = true;
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (!visit[next]) {
			parent[next] = idx;
			go(next);
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	go(1);
	for (int i = 2; i <= N; i++)
		printf("%d\n", parent[i]);
	return 0;
}