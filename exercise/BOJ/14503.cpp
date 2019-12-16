#include<iostream>
using namespace std;
int N, M, R, C, D, map[55][55];
const int mvR[] = { -1, 0, 1, 0 };
const int mvC[] = { 0, 1, 0, -1 };
struct robot {
	int r, c, d;
};
int mvLeft(int dd) {
	return (dd - 1 < 0) ? 3 : dd - 1;
}
int main() {
	scanf("%d%d%d%d%d", &N, &M, &R, &C, &D);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	robot bot = {R, C, D};

	bool isMv = true;
	bool isBack = true;

	while (isMv || isBack) {
		int rpos = bot.r;
		int cpos = bot.c;
		int dir = bot.d;

		map[rpos][cpos] = 2;

		isMv = false;
		for (int k = 1; k <= 4; k++) {
			dir = mvLeft(dir);

			int nextR = rpos + mvR[dir];
			int nextC = cpos + mvC[dir];
			if (map[nextR][nextC] == 1 || map[nextR][nextC] == 2) continue;
			
			isMv = true;
			bot = { nextR, nextC, dir };
			break;
		}
		if (isMv) continue;

		int backDir = (bot.d >= 2) ? bot.d - 2 : bot.d + 2;
		int backR = rpos + mvR[backDir];
		int backC = cpos + mvC[backDir];
		if (map[backR][backC] == 1) isBack = false;
		bot = { backR, backC, bot.d };
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 2) ans++;
	printf("%d\n", ans);
	return 0;
}