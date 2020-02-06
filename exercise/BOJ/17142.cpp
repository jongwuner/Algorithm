#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
const int mvY[] = { 1, 0, -1, 0 };
const int mvX[] = { 0, -1, 0, 1 };
const int INF = 1e8;
vector<pii> vpii;
vector<int> vi;
bool visit[55][55];
int N, M, board[55][55], ans = INF;
int bfs() {
	//clear
	memset(visit, false, sizeof(visit));
	int bfsAns = -INF;
	int tboard[55][55];
	int sboard[55][55];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sboard[i][j] = 0;
			tboard[i][j] = board[i][j];
		}
	}
	// tboard == 0 : 빈칸
	// tboard == 1 : 벽
	// tboard == 2 : 활성
	// tboard == 3 : 비활성

	// visit : 큐가 방문했는지 여부
	// 비활성화 방문하면, 

	queue<pipii> q;

	for (int i = 0; i < vi.size(); i++) {
		int idx = vi[i];
		int y = vpii[idx].first;
		int x = vpii[idx].second;
		q.push({ 0, {y, x} });
		visit[y][x] = true;
	}

	while (!q.empty()) {
		int cnt = q.front().first;
		int py = q.front().second.first;
		int px = q.front().second.second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = py + mvY[k];
			int nx = px + mvX[k];

			if (ny < 1 || N < ny || nx < 1 || N < nx)
				continue;
			if (visit[ny][nx] || tboard[ny][nx] == 1)
				continue;

			visit[ny][nx] = true;
			q.push({ cnt + 1, {ny, nx} });
			sboard[ny][nx] = cnt + 1;
		}
	}

	bool tfg = true;
	bool isSpace = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tboard[i][j] == 0) isSpace = true;
			if (tboard[i][j] == 0) bfsAns = max(bfsAns, sboard[i][j]);
			if (tboard[i][j] != 1 && !visit[i][j]) {
				tfg = false;
			}
		}
	}
	if (!isSpace) {
		return 0;
	}

	return tfg ? bfsAns : INF;
}
void getAnswer(int lev, int idx) {
	if (lev >= M) {
		ans = min(ans, bfs());
		return;
	}
	for (int i = idx + 1; i < vpii.size(); i++) {
		vi.push_back(i);
		getAnswer(lev + 1, i);
		vi.pop_back();
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 2)
				vpii.push_back({ i, j });
		}
	}
	for (int i = 0; i < vpii.size(); i++) {
		getAnswer(0, -1);
	}
	if (ans != INF) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}