#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	// init
	int N, M, ans = 1e8;
	char MAP[55][55];
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}

	// algorithm
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			// board choice
			int R = i;
			int C = j;
			int cnt1 = 0, cnt2 = 0;
			int tmp = 1e8;

			if (R < 1 || R + 7 > N || C < 1 || C + 7 > M) continue;
			for (int r = R; r < R + 8; r++) {
				for (int c = C; c < C + 8; c++) {
					if ((r + c) % 2 == 0) { // even
						if (MAP[r][c] == 'B') cnt1++;
						else cnt2++;
					}
					else { // odd
						if (MAP[r][c] == 'W') cnt1++;
						else cnt2++;
					}
				}
			}
			tmp = min(cnt1, cnt2);
			ans = min(ans, tmp);
		}
	 }
	cout << ans << "\n";
	return 0;
}