#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pair;
const int MAX = 2550;
int N, L, R, ans, mapCnt;
int m[MAX][MAX];
int m2[MAX][MAX]; // numbering
int vcnt[MAX];
int vsum[MAX];
bool visit[MAX][MAX];
vector< vector< vector<Pair> > > adjv;

void dfs(int y, int x) {
	visit[y][x] = true;
	m2[y][x] = mapCnt;
	vcnt[mapCnt]++;
	vsum[mapCnt] += m[y][x];

	for (int i = 0; i < adjv[y][x].size(); i++) {
		int nextY = adjv[y][x][i].first;
		int nextX = adjv[y][x][i].second;
		if (visit[nextY][nextX]) continue;
		dfs(nextY, nextX);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> m[i][j];

	while (1) {
		bool fg = false;
		memset(visit, false, sizeof(visit));
		memset(vcnt, 0, sizeof(vcnt));
		memset(vsum, 0, sizeof(vsum));
		mapCnt = 0;

		adjv.clear();

		adjv.resize(N + 1);
		for (int i = 1; i <= N; i++) adjv[i].resize(N + 1);
			
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i + 1 <= N && L <= abs(m[i + 1][j] - m[i][j]) && abs(m[i + 1][j] - m[i][j]) <= R) {
					adjv[i][j].push_back({ i + 1, j });
					adjv[i + 1][j].push_back({ i, j });
					fg = true;
				}
				if (j + 1 <= N && L <= abs(m[i][j + 1] - m[i][j]) && abs(m[i][j + 1] - m[i][j]) <= R) {
					adjv[i][j].push_back({ i, j + 1 });
					adjv[i][j + 1].push_back({ i, j });
					fg = true;
				}
			}
		}

		if (!fg) break;
		ans++;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!visit[i][j]) {
					mapCnt++;
					dfs(i, j);
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int mapNum = m2[i][j];
				m[i][j] = vsum[mapNum] / vcnt[mapNum];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}