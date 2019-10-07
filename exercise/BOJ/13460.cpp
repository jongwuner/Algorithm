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

			if (NowRed.second == NowBlue.second) { // x��ǥ�� Red�� Blue�� ������?

				if (NowRed.first * updw[k] < NowBlue.first * updw[k]) { // Blue�� �� �ؿ� �ִ���?
					for (int i = 1; i < MAX; i++) {		// BLUE�� �� �ؿ� �ִ� ��Ȳ���� RED���� ���� �б�
						char next = board[NowRed.first + (i * updw[k] * (-1))][NowRed.second];
						if (next == 'O') { // ����
							NextRed = { -1, -1 };
							RedGoal = true;
							break;
						}
						else if (next == '#') { // �Ķ����� �� �ؿ��ֱ⶧���� ���� �� ����.
							NextRed = { NowRed.first + (i - 1)*updw[k] * (-1), NowRed.second };
							break;
						}
					}

					for (int i = 1; i < MAX; i++) { // BLUE�� �� �ؿ� �ִ� ��Ȳ����, RED�о� �װ�, BLUE ���ιб�
						char next = board[NowBlue.first + (i * updw[k] * (-1))][NowBlue.second];
						if (next == 'O') { // BLUE�� ���ۿ� ������ ���, next�� ����.
							NextBlue = { -1, -1 };
							BlueGoal = true;
							break;
						}
						else if ((NextRed.first == NowBlue.first - i) && (NextRed.second == NowBlue.second)) {
							//���� �о�� RED�� BLUE�� �ε��� ��� 
							NextBlue = { NowBlue.first + (i - 1)*updw[k] * (-1), NowBlue.second };
							break;
						}
						else if (next == '#') {
							NextBlue = { NowBlue.first + (i - 1)*updw[k] * (-1), NowBlue.second };
							break;
						}
					}
				}
				else { // Red�� �� �ؿ� �ִ���?
					for (int i = 1; i < MAX; i++) { // RED�� �� �Ʒ� �ִ� ��Ȳ���� BLUE���� ���� �б�
						char next = board[NowBlue.first + (i * updw[k] * (-1))][NowBlue.second];
						if (next == 'O') { // �Ķ��� ���ۿ� ������ ���, next�� ����.
							NextBlue = { -1, -1 };
							BlueGoal = true;
							break;
						}
						else if (next == '#') {
							NextBlue = { NowBlue.first + (i - 1)*updw[k] * (-1), NowBlue.second };
							break;
						}
					}

					for (int i = 1; i < MAX; i++) { // BLUE�о�� ��Ȳ���� RED���� ���� �б�
						char next = board[NowRed.first + (i * updw[k] * (-1))][NowRed.second];
						if (next == 'O') { // RED ���ۿ� ������ ���, NEXT�� ����.
							NextRed = { -1, -1 };
							RedGoal = true;
							break;
						}
						else if ((NowRed.first + (i * updw[k] * (-1)) == NextBlue.first) && (NowRed.second == NextBlue.second)) {
							// ���� �о�� BLUE�� �а� �ִ� RED�� ������. 
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
			else {// x�� Red�� Blue�� �ƿ��޶� ���� �ε��� ��츦 ������� �ʾƵ� �ȴ�.
				for (int i = 1; i < MAX; i++) { // RED ���� �о������
					char next = board[NowRed.first + (i * updw[k] * (-1))][NowRed.second];
					if (next == 'O') { // 0����Ż��.
						NextRed = { -1, -1 };
						RedGoal = true;
						break;
					}

					else if (next == '#') {
						NextRed = { NowRed.first + (i - 1)*updw[k] * (-1), NowRed.second };
						break;
					}

					//BLUE�� ������ ��� 2������ ���.
				}

				for (int i = 1; i < MAX; i++) { //�Ķ��� ���� �о������
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

			if (NowRed.first == NowBlue.first) { // y��ǥ�� Red�� Blue�� ������?

				if (NowRed.second * updw[k] < NowBlue.second * updw[k]) { // Blue�� �� �����ʿ� �ִ���?
					for (int i = 1; i < MAX; i++) {		// BLUE�� �� �����ʿ� �ִ� ��Ȳ���� RED���� ���ʷ� �б�
						char next = board[NowRed.first][NowRed.second + (i * updw[k] * (-1))];
						if (next == 'O') { // ����
							NextRed = { -1, -1 };
							RedGoal = true;
							break;
						}
						else if (next == '#') { // BLUE�� �������ʿ��ֱ⶧���� ���� �� ����.
							NextRed = { NowRed.first, NowRed.second + (i - 1)*updw[k] * (-1) };
							break;
						}
					}

					for (int i = 1; i < MAX; i++) { // BLUE�� �� �����ʿ� �ִ� ��Ȳ����, RED �������� �о� �װ�, BLUE���� ���ʷιб�
						char next = board[NowBlue.first][NowBlue.second + (i * updw[k] * (-1))];
						if (next == 'O') { // BLUE�� ���ۿ� ������ ���, next�� ����.
							NextBlue = { -1, -1 };
							BlueGoal = true;
							break;
						}
						else if ((NextRed.first == NowBlue.first) && (NextRed.second == NowBlue.second + (i * updw[k] * (-1)))) {
							//���� �о�� RED�� BLUE�� �ε��� ��� 
							NextBlue = { NowBlue.first, NowBlue.second + (i - 1)*updw[k] * (-1) };
							break;
						}
						else if (next == '#') {
							NextBlue = { NowBlue.first, NowBlue.second + (i - 1)*updw[k] * (-1) };
							break;
						}
					}
				}
				else { // Red�� �� �����ʿ� �ִ���?
					for (int i = 1; i < MAX; i++) { // RED�� �� �Ʒ� �ִ� ��Ȳ���� BLUE���� ���� �б�
						char next = board[NowBlue.first][NowBlue.second + +(i * updw[k] * (-1))];
						if (next == 'O') { // �Ķ��� ���ۿ� ������ ���, next�� ����.
							NextBlue = { -1, -1 };
							BlueGoal = true;
							break;
						}
						else if (next == '#') {
							NextBlue = { NowBlue.first, NowBlue.second + (i - 1)*updw[k] * (-1) };
							break;
						}
					}

					for (int i = 1; i < MAX; i++) { // BLUE�о�� ��Ȳ���� RED���� ���� �б�
						char next = board[NowRed.first][NowRed.second + (i * updw[k] * (-1))];
						if (next == 'O') { // RED ���ۿ� ������ ���, NEXT�� ����.
							NextRed = { -1, -1 };
							RedGoal = true;
							break;
						}
						else if ((NowRed.first == NextBlue.first) && (NowRed.second + (i * updw[k] * (-1)) == NextBlue.second)) {
							// ���� �о�� BLUE�� �а� �ִ� RED�� ������. 
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
			else {// x�� Red�� Blue�� �ƿ��޶� ���� �ε��� ��츦 ������� �ʾƵ� �ȴ�.
				for (int i = 1; i < MAX; i++) { // RED �������� �о������
					char next = board[NowRed.first][NowRed.second + (i * updw[k] * (-1))];
					if (next == 'O') { // 0����Ż��.
						NextRed = { -1, -1 };
						RedGoal = true;
						break;
					}

					else if (next == '#') {
						NextRed = { NowRed.first, NowRed.second + (i - 1)*updw[k] * (-1) };
						break;
					}

					//BLUE�� ������ ��� 2������ ���.
				}

				for (int i = 1; i < MAX; i++) { //�Ķ��� ���ʷ� �о������
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