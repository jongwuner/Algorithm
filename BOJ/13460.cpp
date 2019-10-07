#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> Pair;
typedef pair<Pair, Pair> PPair;
typedef pair<int, PPair> PPPair;
const int MAX = 15;
const int updw[] = { 1, -1 };
int main() {
	int N, M;
	Pair BluePos, RedPos;
	char board[MAX][MAX];

	queue<PPPair> Q;

	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char tmp;
			scanf(" %c", &tmp);
			if (tmp == 'R') {
				RedPos = { i, j };
			}
			else if (tmp == 'B') {
				BluePos = { i, j };
			}
			else {
				board[i][j] = tmp;
			}
		}
	}
	Q.push({ 0, {RedPos, BluePos } });
	while (!Q.empty()) {
		int cnt = Q.front().first;
		Pair NowRed = Q.front().second.first, NextRed = { -1, -1 };
		Pair NowBlue = Q.front().second.second, NextBlue = { -1, -1 };
		Q.pop();


		// up && Down
		for (int k = 0; k < 2; k++) {
			bool BlueGoal = false, RedGoal = false;

			if (NowRed.second == NowBlue.second) { // x좌표가 Red와 Blue가 같은지?

				if (NowRed.first * updw[k] < NowBlue.first * updw[k]) { // Blue가 더 밑에 있는지?
					for (int i = 1; i < MAX; i++) {		// BLUE가 더 밑에 있는 상황에서 RED부터 위로 밀기
						char next = board[NowRed.first + (i * updw[k] * (-1))][NowRed.second];
						if (next == 'O') { // 구멍
							NextRed = { -1, -1 };
							RedGoal = true;
							break;
						}
						else if (next == '#') { // 파란색이 더 밑에있기때문에 만날 일 없음.
							NextRed = { NowRed.first + (i - 1)*updw[k] * (-1), NowRed.second };
							break;
						}
					}

					for (int i = 1; i < MAX; i++) { // BLUE가 더 밑에 있는 상황에서, RED밀어 뒀고, BLUE 위로밀기
						char next = board[NowBlue.first + (i * updw[k] * (-1))][NowBlue.second];
						if (next == 'O') { // BLUE가 구멍에 빠졌을 경우, next는 없다.
							NextBlue = { -1, -1 };
							BlueGoal = true;
							break;
						}
						else if ((NextRed.first == NowBlue.first - i) && (NextRed.second == NowBlue.second)) {
							//먼저 밀어둔 RED와 BLUE가 부딪힐 경우 
							NextBlue = { NowBlue.first + (i - 1)*updw[k] * (-1), NowBlue.second };
							break;
						}
						else if (next == '#') {
							NextBlue = { NowBlue.first + (i - 1)*updw[k] * (-1), NowBlue.second };
							break;
						}
					}
				}
				else { // Red가 더 밑에 있는지?
					for (int i = 1; i < MAX; i++) { // RED가 더 아래 있는 상황에서 BLUE부터 위로 밀기
						char next = board[NowBlue.first + (i * updw[k] * (-1))][NowBlue.second];
						if (next == 'O') { // 파란색 구멍에 빠졌을 경우, next는 없다.
							NextBlue = { -1, -1 };
							BlueGoal = true;
							break;
						}
						else if (next == '#') {
							NextBlue = { NowBlue.first + (i - 1)*updw[k] * (-1), NowBlue.second };
							break;
						}
					}

					for (int i = 1; i < MAX; i++) { // BLUE밀어둔 상황에서 RED마저 위로 밀기
						char next = board[NowRed.first + (i * updw[k] * (-1))][NowRed.second];
						if (next == 'O') { // RED 구멍에 빠졌을 경우, NEXT는 없다.
							NextRed = { -1, -1 };
							RedGoal = true;
							break;
						}
						else if ((NowRed.first + (i * updw[k] * (-1)) == NextBlue.first) && (NowRed.second == NextBlue.second)) {
							// 먼저 밀어둔 BLUE와 밀고 있는 RED가 만났다. 
							NextRed = { NowRed.first + (i - 1)*updw[k] * (-1), NowRed.second };
							break;
						}
						else if (next == '#') {
							NextRed = { NowRed.first + (i - 1)*updw[k] * (-1), NowRed.second };
							break;
						}
					}
				}
			}
			else {// x가 Red와 Blue가 아예달라서 둘이 부딪힐 경우를 고려하지 않아도 된다.
				for (int i = 1; i < MAX; i++) { // RED 위로 밀어버리기
					char next = board[NowRed.first + (i * updw[k] * (-1))][NowRed.second];
					if (next == 'O') { // 0구멍탈출.
						NextRed = { -1, -1 };
						RedGoal = true;
						break;
					}

					else if (next == '#') {
						NextRed = { NowRed.first + (i - 1)*updw[k] * (-1), NowRed.second };
						break;
					}

					//BLUE와 만날일 없어서 2가지만 고려.
				}

				for (int i = 1; i < MAX; i++) { //파란색 위로 밀어버리기
					char next = board[NowBlue.first + (i * updw[k] * (-1))][NowBlue.second];
					if (next == 'O') {
						NextBlue = { -1, -1 };
						BlueGoal = true;
						break;
					}
					else if (next == '#') {
						NextBlue = { NowBlue.first + (i - 1)*updw[k] * (-1), NowBlue.second };
						break;
					}
				}
			}
			if (RedGoal && !BlueGoal) {
				printf("%d\n", cnt + 1);
				return 0;
			}
			else if (!RedGoal && !BlueGoal && cnt < 10) {
				Q.push({ cnt + 1, {NextRed, NextBlue} });
			}
		}

		//-------------------------------------------------------------------------------------------------------------
				// left && right

		for (int k = 0; k < 2; k++) {
			bool BlueGoal = false, RedGoal = false;

			if (NowRed.first == NowBlue.first) { // y좌표가 Red와 Blue가 같은지?

				if (NowRed.second * updw[k] < NowBlue.second * updw[k]) { // Blue가 더 오른쪽에 있는지?
					for (int i = 1; i < MAX; i++) {		// BLUE가 더 오른쪽에 있는 상황에서 RED부터 왼쪽로 밀기
						char next = board[NowRed.first][NowRed.second + (i * updw[k] * (-1))];
						if (next == 'O') { // 구멍
							NextRed = { -1, -1 };
							RedGoal = true;
							break;
						}
						else if (next == '#') { // BLUE이 더오른쪽에있기때문에 만날 일 없음.
							NextRed = { NowRed.first, NowRed.second + (i - 1)*updw[k] * (-1) };
							break;
						}
					}

					for (int i = 1; i < MAX; i++) { // BLUE가 더 오른쪽에 있는 상황에서, RED 왼쪽으로 밀어 뒀고, BLUE마저 왼쪽로밀기
						char next = board[NowBlue.first][NowBlue.second + (i * updw[k] * (-1))];
						if (next == 'O') { // BLUE가 구멍에 빠졌을 경우, next는 없다.
							NextBlue = { -1, -1 };
							BlueGoal = true;
							break;
						}
						else if ((NextRed.first == NowBlue.first) && (NextRed.second == NowBlue.second + (i * updw[k] * (-1)))) {
							//먼저 밀어둔 RED와 BLUE가 부딪힐 경우 
							NextBlue = { NowBlue.first, NowBlue.second + (i - 1)*updw[k] * (-1) };
							break;
						}
						else if (next == '#') {
							NextBlue = { NowBlue.first, NowBlue.second + (i - 1)*updw[k] * (-1) };
							break;
						}
					}
				}
				else { // Red가 더 오른쪽에 있는지?
					for (int i = 1; i < MAX; i++) { // RED가 더 아래 있는 상황에서 BLUE부터 위로 밀기
						char next = board[NowBlue.first][NowBlue.second + +(i * updw[k] * (-1))];
						if (next == 'O') { // 파란색 구멍에 빠졌을 경우, next는 없다.
							NextBlue = { -1, -1 };
							BlueGoal = true;
							break;
						}
						else if (next == '#') {
							NextBlue = { NowBlue.first, NowBlue.second + (i - 1)*updw[k] * (-1) };
							break;
						}
					}

					for (int i = 1; i < MAX; i++) { // BLUE밀어둔 상황에서 RED마저 위로 밀기
						char next = board[NowRed.first][NowRed.second + (i * updw[k] * (-1))];
						if (next == 'O') { // RED 구멍에 빠졌을 경우, NEXT는 없다.
							NextRed = { -1, -1 };
							RedGoal = true;
							break;
						}
						else if ((NowRed.first == NextBlue.first) && (NowRed.second + (i * updw[k] * (-1)) == NextBlue.second)) {
							// 먼저 밀어둔 BLUE와 밀고 있는 RED가 만났다. 
							NextRed = { NowRed.first, NowRed.second + (i - 1)*updw[k] * (-1) };
							break;
						}
						else if (next == '#') {
							NextRed = { NowRed.first, NowRed.second + (i - 1)*updw[k] * (-1) };
							break;
						}
					}
				}
			}
			else {// x가 Red와 Blue가 아예달라서 둘이 부딪힐 경우를 고려하지 않아도 된다.
				for (int i = 1; i < MAX; i++) { // RED 왼쪽으로 밀어버리기
					char next = board[NowRed.first][NowRed.second + (i * updw[k] * (-1))];
					if (next == 'O') { // 0구멍탈출.
						NextRed = { -1, -1 };
						RedGoal = true;
						break;
					}

					else if (next == '#') {
						NextRed = { NowRed.first, NowRed.second + (i - 1)*updw[k] * (-1) };
						break;
					}

					//BLUE와 만날일 없어서 2가지만 고려.
				}

				for (int i = 1; i < MAX; i++) { //파란색 왼쪽로 밀어버리기
					char next = board[NowBlue.first][NowBlue.second + (i * updw[k] * (-1))];
					if (next == 'O') {
						NextBlue = { -1, -1 };
						BlueGoal = true;
						break;
					}
					else if (next == '#') {
						NextBlue = { NowBlue.first, NowBlue.second + (i - 1)*updw[k] * (-1) };
						break;
					}
				}
			}
			if (RedGoal && !BlueGoal) {
				printf("%d\n", cnt + 1);
				return 0;
			}
			if (!RedGoal && !BlueGoal && cnt < 10) {
				Q.push({ cnt + 1, {NextRed, NextBlue} });
			}
		}
		//----------------------------------------------------------------------------------------------------------
	}
	printf("-1\n");
	return 0;
}