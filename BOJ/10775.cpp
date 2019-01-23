#include<iostream>
#include<vector>
using namespace std;
vector<int> p;
int find(int idx) {
	if (p[idx] < 0) return idx;
	return p[idx] = find(p[idx]);
}
int main() {
	int N, M, ans = 0;
	scanf("%d%d", &N, &M);
	p.resize(N + 1, -1);
	for (int i = 0, node; i <= N; i++) {
		scanf("%d", &node);
		node = find(node);
		if (!node) break;
		p[node] = node - 1;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}