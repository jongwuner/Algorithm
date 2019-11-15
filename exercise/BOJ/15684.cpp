#include<iostream>
using namespace std;
int N, M, H, ans = 1e5;
bool map[35][15];
bool chk() {
	for (int j = 1; j <= N; j++) {
		int curr = j;
		for (int i = 1; i <= H; i++) {
			if (map[i][curr]) curr++;
			else if (map[i][curr - 1]) curr--;
		}
		if (curr != j) return false;
	}
	return true;
}
void getAnswer(int cnt, int y, int x) {
	if (cnt >= ans) return;
	// 체크해서 얘가 i -> i이면 바로 반환	
	if (chk()) {
		ans = cnt;
		return;
	}
	if (cnt == 3) return;
	for (int i = y; i <= H; i++, x = 1) {
		for (int j = x; j < N; j++) {
			if (map[i][j]) {
				j++;
				continue;
			}
			map[i][j] = true;
			getAnswer(cnt + 1, i, j + 2);
			map[i][j] = false;
		}
	}

}
int main() {
	// input : N(2<=N<=10), M, H(1<=H<=30)
	scanf("%d%d%d", &N, &M, &H);
	for (int i = 1, a, b; i <= M; i++) {
		scanf("%d%d", &a, &b);
		map[a][b] = true;
	}
	// algorithm : 
	getAnswer(0, 1, 1);

	// output : 
	if (ans > 3) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}