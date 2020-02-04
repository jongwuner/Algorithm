#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pair;
int T, N;
string S;
map<Pair, int> M;
Pair now, ans;
int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		// clear
		S.clear();
		M.clear();
		bool fg = false;
		now = { 0, 0 };
		ans = { -1e8, 1e8 };
		M[now] = 0;

		scanf("%d", &N);
		cin >> S;
		for (int i = 0; i < N; i++) {
			if (S[i] == 'L') {
				now.first--;
				if (M.find(now) != M.end()) {
					fg = true;
					if (i + 1 - M[now] < ans.second - ans.first) {
						ans = { M[now], i + 1 };
					}
				}
				M[now] = i + 1;
			}
			else if (S[i] == 'R') {
				now.first++;
				if (M.find(now) != M.end()) {
					fg = true;
					if (i + 1 - M[now] < ans.second - ans.first) {
						ans = { M[now], i + 1 };
					}
				}
				M[now] = i + 1;
			}
			else if (S[i] == 'U') {
				now.second++;
				if (M.find(now) != M.end()) {
					fg = true;
					if (i + 1 - M[now] < ans.second - ans.first) {
						ans = { M[now], i + 1 };
					}
				}
				M[now] = i + 1;
			}
			else if (S[i] == 'D') {
				now.second--;
				if (M.find(now) != M.end()) {
					fg = true;
					if (i + 1 - M[now] < ans.second - ans.first) {
						ans = { M[now], i + 1 };
					}
				}
				M[now] = i + 1;
			}
		}
		if (fg) {
			printf("%d %d\n", ans.first + 1, ans.second);
		}
		else printf("-1\n");
	}
	return 0;
}