#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> Pair;
const int MAX = 64;
const int SIZE = 10;
const int mvR[] = { 1, 0, -1, 0 };
const int mvC[] = { 0, -1, 0, 1 };
int N, M;
int InitBoard[SIZE][SIZE], Board[SIZE][SIZE];
bool visit[SIZE][SIZE] = { 0 };
void dfs(int r, int c) {
	
	visit[r][c] = true;
	Board[r][c] = 2;
	for (int k = 0; k < 4; k++) {
		int nextR = r + mvR[k];
		int nextC = c + mvC[k];
		if (nextR < 1 || nextR > N || nextC < 1 || nextC > M) continue;
		if (!visit[r + mvR[k]][c + mvC[k]] && Board[r + mvR[k]][c + mvC[k]] == 0) {
			dfs(r + mvR[k], c + mvC[k]);
		}
	}
}
void BoardInit() {
	for (int i = 0; i < SIZE; i++) 
		for (int j = 0; j < SIZE; j++) 
			Board[i][j] = InitBoard[i][j], visit[i][j] = false;

}
int main() {
	vector<Pair> virList;
	int ans = 0;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &InitBoard[i][j]);
			if (InitBoard[i][j] == 2) {
				virList.push_back({ i, j });
			}
		}
	}

	// 벽 3개선택
	for (int i = 1; i <= MAX; i++) {
		for (int j = i + 1; j <= MAX; j++) {
			for (int k = j + 1; k <= MAX; k++) {

				int fwr = (i - 1) / M + 1;
				int fwc = (i - 1) % M + 1;
				int swr = (j - 1) / M + 1;
				int swc = (j - 1) % M + 1;
				int twr = (k - 1) / M + 1;
				int twc = (k - 1) % M + 1;
				// InitBoard가 1, 2일경우 거기에 벽을 세울수 없음.
				if (fwr < 1 || fwr > N || fwc < 1 || fwc > M) continue;
				if (swr < 1 || swr > N || swc < 1 || swc > M) continue;
				if (twr < 1 || twr > N || twc < 1 || twc > M) continue;
				if (InitBoard[fwr][fwc] || InitBoard[swr][swc] || InitBoard[twr][twc]) continue;

				//init
				int cnt = 0;
				BoardInit(); // 덮어쓰기, visit 초기화
				Board[fwr][fwc] = Board[swr][swc] = Board[twr][twc] = 1;

				for (int l = 0; l < virList.size(); l++) {
					int R = virList[l].first;
					int C = virList[l].second;
					dfs(R, C);
				}
				
				
				for (int ii = 1; ii <= N; ii++) {
					for (int jj = 1; jj <= M; jj++) {
						if (Board[ii][jj] == 0) {
							cnt++;
						}
					}
				}

				//ans = max(ans, cnt);
				if (ans < cnt) {
					ans = cnt;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}