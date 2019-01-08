#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 1005
using namespace std;
typedef pair<int, int> Pair;
const int mvR[] = { 1, 0, -1, 0 };
const int mvC[] = { 0, -1, 0, 1 };
int row, col, ans;
bool arr[MAX][MAX], visit[MAX][MAX];
Pair diaIdx;
void arrToVisit() {
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			visit[i][j] = arr[i][j];
}

void dfs(int r, int c, int lev) {
	visit[r][c] = false;
	if (ans < lev) {
		ans = lev;
		diaIdx = { r, c };
	}
	for (int k = 0; k < 4; k++) {
		int nextR = r + mvR[k];
		int nextC = c + mvC[k];
		if (nextR < 1 || nextR > row || nextC < 1 || nextC > col) continue;
		if (visit[nextR][nextC]) {
			dfs(nextR, nextC, lev + 1);
		}
	}
}

int main() {
	int testCases;
	scanf("%d", &testCases);
	while (testCases--) {
		diaIdx = { 0, 0 }; ans = 0;
		memset(arr, false, sizeof(arr));
		scanf("%d %d", &col, &row);
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				char tmp;
				scanf(" %c", &tmp);
				if (tmp == '.') {
					arr[i][j] = true;
				}
			}
		}
		arrToVisit();
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				if (visit[i][j]) {
					dfs(i, j, 0);
				}
			}
		}
		arrToVisit();
		dfs(diaIdx.first, diaIdx.second, 0);
		printf("Maximum rope length is %d.\n", ans);
	}
	return 0;
}