#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> Pair;
int N, M, cctvNum, cctvType[9], map[9][9], board[9][9], ans = 1e9;
vector<Pair> pos;
vector<int> lis;
void copyArr() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			board[i][j] = map[i][j];
}
void lighten(int opt, Pair pos) {
	int y = pos.first;
	int x = pos.second;

	if (opt == 1) {
		for (int i = y - 1; i >= 1; i--) {
			if (board[i][x] == -1) continue;
			if (board[i][x] == 6 ) break;
			board[i][x] = -1;
		}
	}
	else if (opt == 2) {
		for (int i = y + 1; i <= N; i++) {
			if (board[i][x] == -1) continue;
			if (board[i][x] == 6) break;
			board[i][x] = -1;
		}
	}
	else if (opt == 3) {
		for (int j = x - 1; j >= 1; j--) {
			if (board[y][j] == -1) continue;
			if (board[y][j] == 6) break;
			board[y][j] = -1;
		}
	}
	else if (opt == 4) {
		for (int j = x + 1; j <= M; j++) {
			if (board[y][j] == -1) continue;
			if (board[y][j] == 6) break;
			board[y][j] = -1;
		}
	}
}
void getAnswer(int lev) {
	if (lev > pos.size()) {
		copyArr();
		for (int i = 0; i < pos.size(); i++) {
			if (cctvType[i] == 1) { // 한 방향.
				lighten(lis[i], pos[i]);
			}
			else if (cctvType[i] == 2) { // 180도
				if (lis[i] <= 2) {
					lighten(1, pos[i]);
					lighten(2, pos[i]);
				}
				else {
					lighten(3, pos[i]);
					lighten(4, pos[i]);
				}
			}
			else if (cctvType[i] == 3) { // 90도
				if (lis[i] == 1) {
					lighten(1, pos[i]);
					lighten(4, pos[i]);
				}
				else if (lis[i] == 2) {
					lighten(2, pos[i]);
					lighten(4, pos[i]);
				}
				else if (lis[i] == 3) {
					lighten(2, pos[i]);
					lighten(3, pos[i]);
				}
				else if (lis[i] == 4) {
					lighten(1, pos[i]);
					lighten(3, pos[i]);
				}
			}
			else if (cctvType[i] == 4) { // 세군데
				if (lis[i] != 1) lighten(1, pos[i]);
				if (lis[i] != 2) lighten(2, pos[i]);
				if (lis[i] != 3) lighten(3, pos[i]);
				if (lis[i] != 4) lighten(4, pos[i]);
			}
			else if (cctvType[i] == 5) { // 모든 방향
				lighten(1, pos[i]);
				lighten(2, pos[i]);
				lighten(3, pos[i]);
				lighten(4, pos[i]);
			}
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (board[i][j] == 0) cnt++;
			}
		}
		ans = min(ans, cnt);
		return;
	}
	
	for (int i = 1; i <= 4; i++) {
		lis.push_back(i);
		getAnswer(lev + 1);
		lis.pop_back();
	}

}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0 || map[i][j] == 6) continue;
			pos.push_back({i, j});
			cctvType[pos.size() - 1] = map[i][j];
		}
	}
	cctvNum = pos.size();
	getAnswer(0);
	printf("%d\n", ans);
	return 0;
}