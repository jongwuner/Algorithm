#include<iostream>
#include<vector>
using namespace std;
vector<int> seg;
vector<int> pos;
int segSize;
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
	int testCases;
	scanf("%d", &testCases);
	while (testCases--) {
		int N, M;
		segSize = 1;
		seg.clear();
		pos.clear();
		scanf("%d%d", &N, &M);
		while (segSize < N + M) segSize = segSize << 1;
		seg.resize(2 * segSize);
		pos.resize(N + 1);
		for (int i = 0; i < N; i++) {
			update(i + M, 1);
			pos[i + 1] = i + M;
		}

		for (int i = 1, x; i <= M; i++) {
			scanf("%d", &x);
			printf("%d ", query(0, pos[x] - 1, 1, 0, segSize - 1));
			update(pos[x], 0);
			update(M - i, 1);
			pos[x] = M - i;
		}
		printf("\n");
	}
	return 0;
}