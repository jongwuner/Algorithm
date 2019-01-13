#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int N, a[10005], dp[10005][2];
vector<int> adj[10005];
int getAnswer(int idx, int from, int opt) {
	int &ret = dp[idx][opt];
	if (ret != -1) return ret;

	ret = 0;
	if (opt == 0) {
		for (int next : adj[idx]) {
			if (next != from) {
				int notCho = getAnswer(next, idx, 0);
				int cho = getAnswer(next, idx, 1);
				int val = max(notCho, cho);
				ret += val;
			}
		}
	}
	else if (opt == 1) {
		ret += a[idx];
		for (int next : adj[idx]) {
			if (next != from) {
				ret += getAnswer(next, idx, 0);
			}
		}
	}
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for (int i = 1, a, b; i <= N - 1; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int notChoiced = getAnswer(1, 0, 0);
	int choiced = getAnswer(1, 0, 1);

	printf("%d\n", (choiced >= notChoiced) ? choiced : notChoiced);
	return 0;
}