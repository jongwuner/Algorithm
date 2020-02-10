#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N;
vector<pii> vpii;
vector<int> vi;
int main() {
	scanf("%d", &N);
	vi.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &vi[i]);
	}

	bool fg = false;
	int idx = -1;
	for (int j = 30; j >= 0; j--) {
		int cnt = 0;
		idx = -1;
		for (int i = 0; i < N; i++) {
			if (vi[i] & (1 << j)) {
				cnt++;
				idx = i;
			}
		}
		if (cnt == 1) {
			printf("%d ", vi[idx]);
			fg = true;
			break;
		}
	}
	if (!fg) {
		printf("%d ", vi[0]);
		idx = 0;
	}
	for (int i = 0; i < N; i++) {
		if (i == idx) continue;
		printf("%d ", vi[i]);
	}
	return 0;
}