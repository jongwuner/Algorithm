#include<iostream>
#include<vector>
#define INF 1987654321
using namespace std;
vector<int> p, w;
int find(int idx) {
	if (p[idx] < 0) return idx;
	return p[idx] = find(p[idx]);
}
bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return false;
	if (w[a] < w[b]) p[b] = a;
	else p[a] = b;
	return true;
}
int main() {
	int N, M, k, ans = 0;
	scanf("%d%d%d", &N, &M, &k);
	p.resize(N + 1, -1);
	w.resize(N + 1, INF);

	for (int i = 1; i <= N; i++) scanf("%d", &w[i]);
	for (int i = 1, a, b; i <= M; i++) {
		scanf("%d%d", &a, &b);
		merge(a, b);
	}
	for (int i = 1; i <= N; i++) {
		if (find(0) != find(i)) {
			ans += w[find(i)];
			merge(0, i);
		}
	}
	if (ans <= k) printf("%d\n", ans);
	else printf("Oh no\n");
	return 0;
}