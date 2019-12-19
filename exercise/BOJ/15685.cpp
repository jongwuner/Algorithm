#include<iostream>
#include<stack>
using namespace std;
const int mvY[] = {0, -1, 0, 1};
const int mvX[] = {1, 0, -1, 0};
const int recY[] = { 0, 0, 1, 1 };
const int recX[] = { 0, 1, 0, 1 };
struct curve {
	int y, x, d, g;
};
int board[105][105], ans;
curve c[25];
typedef pair<int, int> Pair;

void getAnswer() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			bool flag = true;
			for (int k = 0; k < 4; k++) {
				if (board[i + recY[k]][j + recX[k]] == 0) {
					flag = false;
					break;
				}
			}
			if (flag) ans++;
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d%d%d", &c[i].x, &c[i].y, &c[i].d, &c[i].g);

		int currY = c[i].y;
		int currX = c[i].x;
		int currD = c[i].d;
		int currG = c[i].g;

		board[currY][currX] = 1;
		board[currY + mvY[c[i].d]][currX + mvX[c[i].d]] = 1;

		stack<int> s[2];
		int stIdx = 0;
		s[stIdx].push(currD);
		s[stIdx ^ 1] = s[stIdx];

		currY += mvY[currD];
		currX += mvX[currD];

		for (int k = 1; k <= c[i].g; k++) {
			while (!s[stIdx].empty()) {
				currD = (s[stIdx].top() + 1 > 3) ? 0 : s[stIdx].top() + 1;
				s[stIdx ^ 1].push(currD);

				currY = currY + mvY[currD];
				currX = currX + mvX[currD];
				board[currY][currX] = 1;

				s[stIdx].pop();
			}
			stIdx = stIdx ^ 1;
			s[stIdx ^ 1] = s[stIdx];
		}
	}
	getAnswer();
	printf("%d\n", ans);
	return 0;
}