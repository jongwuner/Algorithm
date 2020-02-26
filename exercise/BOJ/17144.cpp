#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pair;
const int MAX = 55;
const int mvR[] = { 1, 0, -1, 0 };
const int mvC[] = { 0, -1, 0, 1 };
int R, C, T;
vector<Pair> vccm;
ll m1[MAX][MAX], m2[MAX][MAX], ans;
void vccmMv() {

	for (int i = 0; i <= 1; i++) {
		int r = vccm[i].first;
		int c = vccm[i].second;
		int nextR = r;
		int nextC = c;
		r += (i == 0 ? -1 : 1);
		while (r != vccm[i].first || c != vccm[i].second) {

			if (c == 1 && 1 < r && r <= vccm[0].first)
				nextR = r - 1, nextC = c;
			else if (r == 1 && c < C)
				nextR = r, nextC = c+1;
			else if (c == C && 1 <= r && r < vccm[0].first)
				nextR = r + 1, nextC = c;
			else if (r == vccm[0].first && c <= C)
				nextR = r, nextC = c-1;

			else if (c == 1 && vccm[1].first <= r && r < R)
				nextR = r+1, nextC = c;
			else if (r == R && c < C)
				nextR = r, nextC = c+1;
			else if (c == C && vccm[1].first < r && r <= R)
				nextR = r-1, nextC = c;
			else if (r == vccm[1].first && c <= C)
				nextR = r, nextC = c-1;

			if (!((nextR == vccm[0].first && nextC == vccm[0].second) || (nextR == vccm[1].first && nextC == vccm[1].second)))
				m1[r][c] = m1[nextR][nextC];
			else
				m1[r][c] = 0;

			r = nextR; c = nextC;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) {
		cin >> m1[i][j];
		if (m1[i][j] == -1)
			vccm.push_back({ i, j });
	}
	
	for (int i = 1; i <= T; i++) {
		// clear

		// init

		// algoritm
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (m1[i][j] == -1) continue;
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nextR = i + mvR[k];
					int nextC = j + mvC[k];
					if (nextR < 1 || nextR > R || nextC < 1 || nextC > C) continue;
					if (m1[nextR][nextC] == -1) continue;
					m2[nextR][nextC] += (m1[i][j] / 5);
					cnt++;
				}
				m2[i][j] -= (m1[i][j]/5) * cnt;
			}
		}
		for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) 
			m1[i][j] += m2[i][j], m2[i][j] = 0;
		
		vccmMv();

	}

	for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) if(m1[i][j] != -1) ans += m1[i][j];
	cout << ans << "\n";
	return 0;
}