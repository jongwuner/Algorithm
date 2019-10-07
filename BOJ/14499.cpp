#include<iostream>
using namespace std;
int dice[7] = { 0, 0, 0, 0, 0, 0, 0 };
const int mvY[] = { 0, 0, 0, -1, 1 };
const int mvX[] = { 0, 1, -1, 0, 0 };

void swapRight() {
	int tmp = dice[6];
	dice[6] = dice[2];
	dice[2] = dice[5];
	dice[5] = dice[4];
	dice[4] = tmp;
}
void swapLeft() {
	int tmp = dice[6];
	dice[6] = dice[4];
	dice[4] = dice[5];
	dice[5] = dice[2];
	dice[2] = tmp;
}
void swapUp() {
	int tmp = dice[4];
	dice[4] = dice[1];
	dice[1] = dice[2];
	dice[2] = dice[3];
	dice[3] = tmp;
}
void swapDown() {
	int tmp = dice[4];
	dice[4] = dice[3];
	dice[3] = dice[2];
	dice[2] = dice[1];
	dice[1] = tmp;
}
int main() {
	// input
	int N, M, K, board[25][25], dir, nowY, nowX;


	scanf("%d%d%d%d%d", &N, &M, &nowY, &nowX, &K);
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			scanf("%d", &board[i][j]);

	nowY++; nowX++;
	dice[4] = (board[nowY][nowX] == 0) ? dice[4] : board[nowY][nowX];

	for (int i = 1; i <= K; i++) {
		// 1: 동
		// 2: 서
		// 3: 북
		// 4: 남
		scanf("%d", &dir);
		
		//algorithm
		int nextY = nowY + mvY[dir];
		int nextX = nowX + mvX[dir];
		if (nextY < 1 || nextY > N || nextX < 1 || nextX > M) continue;


		if (dir == 1) swapRight();
		else if (dir == 2) swapLeft();
		else if (dir == 3) swapUp();
		else if (dir == 4) swapDown();

		if (board[nextY][nextX] == 0) {
			// 지도의 칸이 0이면 
			// 주사위 -> 지도
			board[nextY][nextX] = dice[4];
		}
		else {
			// 지도의 칸이 0이 아니면?
			// 지도 -> 주사위 && 지도 0
			dice[4] = board[nextY][nextX];
			board[nextY][nextX] = 0;
		}
		// output
		printf("%d\n", dice[2]);

		nowY = nextY;
		nowX = nextX;
	}
	return 0;
}