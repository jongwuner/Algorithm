#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll> seg;
int segSize = 1, N, M;
void update(int idx, ll val) {
	idx += segSize;
	seg[idx] += val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
}
ll query(int L, int R, int nodeIdx, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return seg[nodeIdx];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, 2 * nodeIdx, nodeL, mid) + query(L, R, 2 * nodeIdx + 1, mid + 1, nodeR);
}
int main() {
	scanf("%d%d", &N, &M);
	while (segSize < N) segSize = segSize << 1;
	seg.resize(2 * segSize, 0);
	for (int i = 0, a; i < M; i++) {
		scanf("%d", &a);
		if (a == 1) {
			ll val;
			int b;
			scanf("%d%lld", &b, &val);
			update(b - 1, val);
		}
		else if (a == 2) {
			int b, c;
			scanf("%d%d", &b, &c);
			printf("%lld\n", query(b - 1, c - 1, 1, 0, segSize - 1));
		}
	}
	return 0;
}