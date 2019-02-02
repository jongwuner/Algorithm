#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> Pair;
int N, segSize = 1;
vector<Pair> tn;
vector<int> seg;
void update(int idx, int val) {
	idx += segSize;
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
}
int sumQuery(int L, int R, int nodeIdx, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return seg[nodeIdx];
	int mid = (nodeL + nodeR) / 2;
	return sumQuery(L, R, 2 * nodeIdx, nodeL, mid) + sumQuery(L, R, 2 * nodeIdx + 1, mid + 1, nodeR);
}
int main() {
	scanf("%d", &N);
	while (segSize < N) segSize = segSize << 1;
	seg.resize(2 * segSize);
	for (int i = 0, tmp; i < N; i++) {
		scanf("%d", &tmp);
		tn.push_back({tmp, i});
	}
	sort(tn.begin(), tn.end());
	for (int i = 0; i < N; i++) {
		seg[i + segSize] = 1;
		update(i, 1);
	}
	for (int i = 0; i < N; i++) {
		int L, R;
		if (i % 2) { 
			printf("%d\n", sumQuery(tn[N - 1 - i / 2].second, N - 1, 1, 0, segSize - 1) - 1);
			update(tn[N - 1 - i / 2].second, 0);
		}
		else { 
			printf("%d\n", sumQuery(0, tn[i / 2].second, 1, 0, segSize - 1) - 1);
			update(tn[i / 2].second, 0);
		}
	}
	return 0;
}