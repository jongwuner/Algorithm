#include<iostream>
#include<vector>
using namespace std;
int segSize = 1, N, M;
vector<int> seg;
void update(int idx, int val) {
	idx += segSize;
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
}
int query(int L, int R, int nodeIdx, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return seg[nodeIdx];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, 2 * nodeIdx, nodeL, mid) + query(L, R, 2 * nodeIdx + 1, mid + 1, nodeR);
}
int main() {
	scanf("%d%d", &N, &M);
	while (segSize < N) segSize = segSize << 1;
	seg.resize(2 * segSize);
	for (int i = 0, opt; i < M; i++) {
		scanf("%d", &opt);
		if (opt == 1) {
			int a, b;
			scanf("%d%d", &a, &b);
			update(a, b);
		}
		else if (opt == 2) {
			int a, b;
			scanf("%d%d", &a, &b);
			query(a, b, 1, 0, segSize - 1);
		}
	}
}