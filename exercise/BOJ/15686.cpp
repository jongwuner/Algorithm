#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef pair<int, int> Pair;
int N, M, map[55][55], board[55][55], ans = 1e9;

vector<Pair> chk;
Pair dis[15];
vector<int> lis;
bool chkVisit[15];

void copyArr() {
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			board[i][j] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 2) continue;
			board[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < lis.size(); i++) {
		int currY = chk[lis[i]].first;
		int currX = chk[lis[i]].second;
		board[currY][currX] = 2;
	}
}
void getAnswer(int lev, int idx) {
	if (lev >= M) {
		int chkDis = 0;
		copyArr();
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] == 1) {
					int disVal = 1e9;
					for (int k = 0; k < lis.size(); k++) {
						int chkY = chk[lis[k]].first;
						int chkX = chk[lis[k]].second;
						disVal = min(disVal, abs(chkY - i) + abs(chkX - j));
					}
					chkDis += disVal;
				}
			}
		}
		ans = min(ans, chkDis);
		return;
	}
	for (int i = idx; i < chk.size(); i++) {
		if (chkVisit[i]) continue;
		chkVisit[i] = true;
		lis.push_back(i);
		getAnswer(lev + 1, i + 1);
		lis.pop_back();
		chkVisit[i] = false;
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) 
				chk.push_back({ i, j });
		}
	}
	
	getAnswer(0, 0);

	printf("%d\n", ans);
	return 0;
}