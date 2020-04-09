#include<bits/stdc++.h>
using namespace std;
const int mvY[] = { 1, 0, -1, 0 };
const int mvX[] = { 0, -1, 0, 1 };
int N, M, n, m;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	int T; cin >> T; while (T--) {
		cin >> N >> M;
 
		int cntB = 0, cntW = 0;
		char MAP[105][105];
 
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if ((i + j) % 2 == 0) {
					MAP[i][j] = 'B';
					cntB++;
				}
				else {
					MAP[i][j] = 'W';
					cntW++;
				}
			}
		}
		if (cntW == cntB) {
			bool ans = true;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (MAP[i][j] == 'W') {
						MAP[i][j] = 'B';
						ans = false;
						break;
					}
				}
				if (!ans) break;
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cout << MAP[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}