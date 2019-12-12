#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int N, K;
int board[20][20];
const int mvY[] = { 0, 0, 0, -1, 1 };
const int mvX[] = { 0, 1, -1, 0, 0 };
vector<int> chess[20][20];
queue<int> Q;
stack<int> S;
struct Horse {
	int y, x, d;
};
Horse horse[15];
bool isValid(int Y, int X) {
	return 1 <= Y && Y <= N && 1 <= X && X <= N;
}
int main() {

	scanf("%d%d", &N, &K);
	for (int i = 1, tmp; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	for (int i = 1; i <= K; i++) {
		scanf("%d%d%d", &horse[i].y, &horse[i].x, &horse[i].d);
		chess[horse[i].y][horse[i].x].push_back(i);
	}

	int ans = 0;
	while (++ans <= 1000) {
		for (int i = 1; i <= K; i++) {
			// ÆÄ¶õ»ö || ¹üÀ§ ¹Ù±ùÀ¸·Î
			int nextY = horse[i].y + mvY[horse[i].d];
			int nextX = horse[i].x + mvX[horse[i].d];
			if (!isValid(nextY, nextX) || board[nextY][nextX] == 2) {
				if (horse[i].d % 2 == 0)
					horse[i].d--;
				else
					horse[i].d++;

				nextY = horse[i].y + mvY[horse[i].d];
				nextX = horse[i].x + mvX[horse[i].d];
				if (!isValid(nextY, nextX) || board[nextY][nextX] == 2) continue;
				i--;
			}
			// »¡°£»ö
			else if (board[nextY][nextX] == 1) {
				int idx;
				for (idx = 0; chess[horse[i].y][horse[i].x][idx] != i; idx++);
				for (int j = idx; j < chess[horse[i].y][horse[i].x].size(); j++)
					S.push(chess[horse[i].y][horse[i].x][j]);
				while (chess[horse[i].y][horse[i].x].size() > idx)
					chess[horse[i].y][horse[i].x].pop_back();
				while (!S.empty()) {
					chess[nextY][nextX].push_back(S.top());
					horse[S.top()].y = nextY;
					horse[S.top()].x = nextX;
					S.pop();
				}
			}
			// Èò»ö
			else {
				int idx;
				for (idx = 0; chess[horse[i].y][horse[i].x][idx] != i; idx++);
				for (int j = idx; j < chess[horse[i].y][horse[i].x].size(); j++)
					Q.push(chess[horse[i].y][horse[i].x][j]);
				while (chess[horse[i].y][horse[i].x].size() > idx)
					chess[horse[i].y][horse[i].x].pop_back();
				while (!Q.empty()) {
					chess[nextY][nextX].push_back(Q.front());
					horse[Q.front()].y = nextY;
					horse[Q.front()].x = nextX;
					Q.pop();
				}
			}
			if (chess[horse[i].y][horse[i].x].size() >= 4) {
				printf("%d\n", ans);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}