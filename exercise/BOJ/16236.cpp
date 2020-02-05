#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipi;
typedef pair<int, pair<pii, pii>> pipipi;
struct shark{
	int sec, age, ate;
	pii pos;
};
const int mvY[] = { 1, 0, -1, 0 };
const int mvX[] = { 0, -1, 0, 1 };

bool visit[25][25];
vector<pipipi> vpipipi;
int N, M[25][25];
int age, ate;
pii sp;
int bfs() {
	queue<shark> q;
	q.push({ 0, age, ate, sp });
	visit[sp.first][sp.second] = true;
	while (!q.empty()) {
		int now_sec = q.front().sec;
		int now_age = q.front().age;
		int now_ate = q.front().ate;
		int now_y = q.front().pos.first;
		int now_x = q.front().pos.second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int next_y = now_y + mvY[k];
			int next_x = now_x + mvX[k];
			if (next_y < 1 || next_y > N || next_x < 1 || next_x > N)
				continue;
			if (visit[next_y][next_x] || now_age < M[next_y][next_x])
				continue;


			visit[next_y][next_x] = true;
			if (M[next_y][next_x] && now_age > M[next_y][next_x]) {
				if (now_ate + 1 == now_age) {
					vpipipi.push_back({ now_sec + 1, {{next_y, next_x}, {now_age + 1, 0}} });
				}
				else {
					vpipipi.push_back({ now_sec + 1, {{next_y, next_x}, {now_age, now_ate + 1}} });
				}
			}
			else {
				q.push({ now_sec + 1, now_age, now_ate, {next_y, next_x} });
			}
		}
	}
	if (!vpipipi.empty()) {
		sort(vpipipi.begin(), vpipipi.end());
		sp = vpipipi[0].second.first;
		age = vpipipi[0].second.second.first;
		ate = vpipipi[0].second.second.second;
		M[sp.first][sp.second] = 0;
		return vpipipi[0].first;
	}
	else return 0;
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &M[i][j]);
			if (M[i][j] == 9) {
				M[i][j] = 0;
				age = 2;
				sp = { i, j };
			}
		}
	}
	int ans = 0;
	while (1) {
		// clear
		memset(visit, false, sizeof(visit));
		vpipipi.clear();
		ans += bfs();
		if (vpipipi.empty()) break;
	}
	printf("%d\n", ans);
	return 0;
}