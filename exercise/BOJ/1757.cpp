#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;
int N, M, a[10005], dp[10005][505][2];
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) 
		scanf("%d", &a[i]);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = -INF;

	dp[1][0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i][j][0] != -INF) {
				if (j + 1 <= M) 
					dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][0] + a[i]);
				if (j - 1 >= 0) {
					dp[i + 1][j - 1][1] = max(dp[i + 1][j - 1][0], dp[i][j][0]);
					if (j - 1 == 0) {
						dp[i + 1][j - 1][0] = max(dp[i + 1][j - 1][0], dp[i][j][0]);
					}
				}
			}
			if (dp[i][j][1] != -INF) {
				if (j - 1 >= 0) {
					dp[i + 1][j - 1][1] = max(dp[i + 1][j - 1][1], dp[i][j][1]);
					if (j - 1 == 0) {
						dp[i + 1][j - 1][0] = max(dp[i + 1][j - 1][0], dp[i][j][1]);
					}
				}
			}
			if (j == 0) {
				dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][0]);
			}
		}
	}
	printf("%d\n", dp[N + 1][0][0]);
	return 0;
}