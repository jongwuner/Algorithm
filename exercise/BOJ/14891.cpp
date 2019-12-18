#include<iostream>
using namespace std;
typedef pair<int, int> Pair;
int top[5][9], K;
int chg[5];
Pair p[105];
int main() {
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 8; j++)
			scanf("%1d", &top[i][j]);
	scanf("%d", &K);
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= 4; j++) chg[j] = 0;
		scanf("%d%d", &p[i].first, &p[i].second);

		int target = p[i].first;
		chg[target] = p[i].second;
		
		for (int j = target + 1; j <= 4; j++) {
			if (top[j - 1][3] == top[j][7]) break;
			chg[j] = chg[j - 1] * -1;
		}

		for (int j = target - 1; j >= 1; j--) {
			if (top[j][3] == top[j + 1][7]) break;
			chg[j] = chg[j + 1] * -1;
		}

		for (int j = 1; j <= 4; j++) {
			if (chg[j] == 0) continue;
			if (chg[j] == 1) { // 시계방향
				int tmp = top[j][8];
				for (int k = 7; k >= 1; k--) {
					top[j][k + 1] = top[j][k];
				}
				top[j][1] = tmp;
			}

			else if (chg[j] == -1) { // 반시계
				int tmp = top[j][1];
				for (int k = 1; k <= 7; k++) {
					top[j][k] = top[j][k + 1];
				}
				top[j][8] = tmp;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++)
		if (top[i + 1][1] == 1) 
			ans += (1 << i);
	printf("%d\n", ans);
	return 0;
}