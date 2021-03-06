#include"stdafx.h"
#include<iostream>
#include<queue>
#include<algorithm>
#define MAX1 1005
#define MAX2 15
#define INF 1e9
using namespace std;
typedef pair<int, int> Pair;
const int mvY[4] = {1, 0, -1, 0};
const int mvX[4] = {0, -1, 0, 1};
int N, M, K, dp[MAX1][MAX1][MAX2], ans = INF;
char a[1005][1005];
bool visit[MAX1][MAX1];
queue<Pair> q;
int main() {
	scanf_s("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s(" %c", &a[MAX1][MAX1]);
			for (int k = 1; k <= K; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	
	q.push({1, 1});
	visit[1][1] = true;
	dp[1][1][0] = 1;

	while (!q.empty()) {
		int ypos = q.top().first;
		int xpos = q.top().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nextY = ypos + mvY[k];
			int nextX = xpos + mvX[k];
			if (nextY < 1 || nextY > N || nextX < 1 || nextX > M) continue;
			if (!visit[nextY][nextX]) {
				visit[nextY][nextX] = true;
				q.push({nextY, nextX});
			}
			for (int kk = 0; kk < K; kk++) {
				if (a[nextY][nextX] == '1') {
					if (dp[nextY][nextX][kk + 1] > dp[ypos][xpos][kk] + 1) {
						dp[nextY][nextX][kk + 1] = dp[ypos][xpos][kk] + 1;
					}
				}
				else {
					if (dp[nextY][nextX][kk] > dp[ypos][xpos][kk] + 1) {
						dp[nextY][nextX][kk] = dp[ypos][xpos][kk] + 1;
					}
				}
			}
		}
	}
	for (int k = 0; k <= K; k++) {
		ans = min(ans, dp[N][M][k]);
	}

	printf("%d\n", (ans != INF) ? ans : -1);
	return 0;
}