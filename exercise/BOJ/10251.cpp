#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX 105
#define TIME 205
using namespace std;

int TC, dp[105][105][205][2];
int M, N, L, G;

int main() {
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		memset(dp, -1, sizeof(dp));
		int wmap[105][105], hmap[105][105];
		scanf("%d%d%d%d", &M, &N, &L, &G);
		for (int i = 1; i <= M; i++)
			for (int j = 1; j <= N - 1; j++)
				scanf("%d", &wmap[i][j]);

		for (int i = 1; i <= M - 1; i++)
			for (int j = 1; j <= N; j++)
				scanf("%d", &hmap[i][j]);

		dp[1][1][0][0] = dp[1][1][0][1] = G;

		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == 1 && j == 1) continue;
				if (i == 1) {
					dp[i][j][0][0] = (dp[i][j - 1][0][0] - wmap[i][j - 1] >= 0) ? dp[i][j - 1][0][0] - wmap[i][j - 1] : -1;
					continue;
				}
				if (j == 1) {
					dp[i][j][0][1] = (dp[i - 1][j][0][1] - hmap[i - 1][j] >= 0) ? dp[i - 1][j][0][1] - hmap[i - 1][j] : -1;
					continue;
				}

				for (int t = 0; t <= min(i, j) * 2; t++) {
					
					int &now_L0_0 = dp[i][j][t][0];
					int &now_L0_1 = dp[i][j][t][1];
					int &now_L1_0 = dp[i][j][t + 1][0];
					int &now_L1_1 = dp[i][j][t + 1][1];

					int &left0 = dp[i][j - 1][t][0];
					int &left1 = dp[i][j - 1][t][1];
					int &up0 = dp[i - 1][j][t][0];
					int &up1 = dp[i - 1][j][t][1];

					if (left0 - wmap[i][j - 1] >= 0)
						now_L0_0 = max(now_L0_0, left0 - wmap[i][j - 1]);
					
					if (left1 - wmap[i][j - 1] >= 0)
						now_L1_0 = max(now_L1_0, left1 - wmap[i][j - 1]);
					
					if (up0 - hmap[i - 1][j] >= 0)
						now_L1_1 = max(now_L1_1, up0 - hmap[i - 1][j]);
					
					if (up1 - hmap[i - 1][j] >= 0)
						now_L0_1 = max(now_L0_1, up1 - hmap[i - 1][j]);
				}
			}
		}

		bool flag = false;
		for (int i = 0; i <= min(M, N) * 2; i++) {
			if (dp[M][N][i][0] > 0 || dp[M][N][i][1] > 0) {
				printf("%d\n", (M + N - 2) * L + i);
				flag = true;
				break;
			}
		}
		if (!flag) printf("-1\n");
	}
	return 0;
}