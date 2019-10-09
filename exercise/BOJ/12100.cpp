#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> Pair;
typedef pair<int, Pair> PPair;
const int MAX = 25;

int N, ans = 1;
void DFS(int lev, vector<vector<int>> Now) {
	if (lev >= 5) return;

	vector<vector<int>> Next;

	// 그대로---------------------------------------------------------
	Next = Now;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			ans = max(ans, Next[i][j]);

	DFS(lev + 1, Next);
	Next.clear();
	//down--------------------------------------------------------------
	Next = Now;
	for (int j = 1; j <= N; j++) {
		int object = -1; // merge할 object가 없다.
		for (int i = N; i >= 1; i--) {
			if (Next[i][j]) {
				if (object == -1)
					object = i; // merge할 object를 지금 찾았다.
				else if (Next[object][j] == Next[i][j]) {
					Next[object][j] += Next[i][j];
					Next[i][j] = 0;
					object = -1;
				}
				else {
					object = -1;
					i++;
				}
			}
		}
	}
	// down-mv : 0을 메꿔서 땡긴다!, 0을 잡고 다음 tartget을 여기까지 땡긴다!
	for (int j = 1; j <= N; j++) {
		for (int i = N; i >= 1; i--) {
			ans = max(ans, Next[i][j]);
			if (Next[i][j]) continue;
			for (int k = i - 1; k >= 1; k--) {
				if (Next[k][j]) {
					Next[i][j] = Next[k][j];
					Next[k][j] = 0;
					break;
				}
			}
		}
	}

	DFS(lev + 1, Next);
	Next.clear();
	//left-----------------------------------------------------------------
		// merge : object 1개가 target 1잡고, 합치기!, target은 0이된다.
	Next = Now;

	for (int i = 1; i <= N; i++) {
		int object = -1; // merge할 object가 없다.
		for (int j = 1; j <= N; j++) {
			if (Next[i][j]) {
				if (object == -1)
					object = j; // merge할 object를 지금 찾았다.
				else if (Next[i][object] == Next[i][j]) {
					Next[i][object] += Next[i][j];
					Next[i][j] = 0;
					object = -1;
				}
				else {
					object = -1;
					j--;
				}
			}
		}
	}
	// left - mv : 0을 메꿔서 땡긴다!, 0을 잡고 다음 tartget을 여기까지 땡긴다!
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans = max(ans, Next[i][j]);
			if (Next[i][j]) continue;
			for (int k = j + 1; k <= N; k++) {
				if (Next[i][k]) {
					Next[i][j] = Next[i][k];
					Next[i][k] = 0;
					break;
				}
			}
		}
	}

	DFS(lev + 1, Next);
	Next.clear();
	//up-----------------------------------------------------------------
	Next = Now;

	for (int j = 1; j <= N; j++) {
		int object = -1; // merge할 object가 없다.
		for (int i = 1; i <= N; i++) {
			if (Next[i][j]) {
				if (object == -1)
					object = i; // merge할 object를 지금 찾았다.
				else if (Next[object][j] == Next[i][j]) {
					Next[object][j] += Next[i][j];
					Next[i][j] = 0;
					object = -1;
				}
				else {
					object = -1;
					i--;
				}
			}
		}
	}

	// up-mv : 0을 메꿔서 땡긴다!, 0을 잡고 다음 tartget을 여기까지 땡긴다!
	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= N; i++) {
			ans = max(ans, Next[i][j]);
			if (Next[i][j]) continue;
			for (int k = i + 1; k <= N; k++) {
				if (Next[k][j]) {
					Next[i][j] = Next[k][j];
					Next[k][j] = 0;
					break;
				}
			}
		}
	}

	DFS(lev + 1, Next);
	Next.clear();
	//right---------------------------------------------------------------
	Next = Now;
	for (int i = 1; i <= N; i++) {
		int object = -1; // merge할 object가 없다.
		for (int j = N; j >= 1; j--) {
			if (Next[i][j]) {
				if (object == -1)
					object = j; // merge할 object를 지금 찾았다.
				else if (Next[i][object] == Next[i][j]) {
					Next[i][object] += Next[i][j];
					Next[i][j] = 0;
					object = -1;
				}
				else {
					object = -1;
					j++;
				}
			}
		}
	}

	// right-mv : 0을 메꿔서 땡긴다!, 0을 잡고 다음 tartget을 여기까지 땡긴다!
	for (int i = 1; i <= N; i++) {
		for (int j = N; j >= 1; j--) {
			ans = max(ans, Next[i][j]);
			if (Next[i][j]) continue;
			for (int k = j - 1; k >= 1; k--) {
				if (Next[i][k]) {
					Next[i][j] = Next[i][k];
					Next[i][k] = 0;
					break;
				}
			}
		}
	}
	DFS(lev + 1, Next);
	Next.clear();
}
int main() {
	// input
	vector< vector<int> > board;
	scanf("%d", &N);
	board.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		board[i].resize(N + 1);
		for (int j = 1; j <= N; j++)
			scanf("%d", &board[i][j]);
	}
	// algorithm
	DFS(0, board);
	// output
	printf("%d\n", ans);
	return 0;
}