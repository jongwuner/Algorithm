#include<bits/stdc++.h>
using namespace std;
const int mvY[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int mvX[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int MAP[55][55];

void DFS(int y, int x) {
	MAP[y][x] = 0;
	for (int k = 0; k < 8; k++) {
		int nextY = y + mvY[k];
		int nextX = x + mvX[k];
		if (MAP[nextY][nextX] == 1) {
			DFS(nextY, nextX);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);


	int w, h, ans;
	while (1) {
		// init
		memset(MAP, 0, sizeof(MAP));
		ans = 0;
		cin >> w >> h;

		// algorithm
		if (w == 0 && h == 0) break;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> MAP[i][j];
			}
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (MAP[i][j] == 1) {
					ans++;
					DFS(i, j);
				}
			}
		}

		//output
		cout << ans << "\n";
	}
	return 0;
}