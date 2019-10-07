#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> Pair;
const int INF = 1234567890;
vector<Pair> seg; // first : MAX , second : MIN
int segSize;
Pair query(int L, int R, int nodeIdx, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return {-INF, INF};
	if (L <= nodeL && nodeR <= R) return seg[nodeIdx];
	int mid = (nodeL + nodeR) / 2;
	Pair Left = query(L, R, nodeIdx * 2, nodeL, mid);
	Pair Right = query(L, R, nodeIdx * 2 + 1, mid + 1, nodeR);
	return { max(Left.first, Right.first), min(Left.second, Right.second) };
}
void update(int idx, int val) {
	idx += segSize;
	seg[idx] = { val, val };
	while (idx > 1) {
		idx /= 2;
		seg[idx].first = max(seg[idx * 2].first, seg[idx * 2 + 1].first);
		seg[idx].second = min(seg[idx * 2].second, seg[idx * 2 + 1].second);
	}
}
int main() {
	int testCases, N, M;
	scanf("%d", &testCases);
	while (testCases--) {
		segSize = 1;
		seg.clear();
		
		scanf("%d%d", &N, &M);
		while (segSize < N) segSize = segSize << 1;
		seg.resize(2 * segSize);
		for (int i = 0; i < segSize; i++) 
			update(i, i);
	

		for (int i = 0, k; i < M; i++) {
			scanf("%d", &k);
			if (k == 0) {
				int a, b;
				Pair tmp;
				scanf("%d%d", &a, &b);
				tmp = seg[segSize + a];
				update(a, seg[segSize + b].first);
				update(b, tmp.first);
			}
			else if (k == 1) {
				int a, b;
				scanf("%d%d", &a, &b);
				Pair ans = query(a, b, 1, 0, segSize - 1);
				if (ans.first == b && ans.second == a) {
					printf("YES\n");
				}
				else printf("NO\n");
			}
		}
	}
	return 0;
}