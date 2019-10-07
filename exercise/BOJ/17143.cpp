#include<iostream>
#include<cstring>
using namespace std;
struct shark {
	int speed, dir, siz;
};
int R, C, M, ans;
shark a[105][105];
const int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

void solve() {
	for (int t = 0; t < C; t++) {
		shark b[105][105] = { 0 };
		// Fishing a shark
		for (int i = 0; i < R; i++) {
			if (a[i][t].siz) {
				ans += a[i][t].siz;
				a[i][t] = { 0, 0, 0 };
				break;
			}
		}
		// Shark move
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (a[i][j].siz) {
					if (a[i][j].dir < 2) { // UP, DOWN
						int s = a[i][j].speed % ((R - 1) * 2);
						int d = a[i][j].dir;
						int ni = i;
						while (s--) {
							if (ni == 0 && d == 0) d = 1;
							if (ni == R - 1 && d == 1) d = 0;
							ni += dx[d];
						}
						if (a[i][j].siz > b[ni][j].siz)
							b[ni][j] = { a[i][j].speed, d, a[i][j].siz };
					}
					else { // RIGHT, LEFT
						int s = a[i][j].speed % ((C - 1) * 2);
						int d = a[i][j].dir;
						int nj = j;
						while (s--) {
							if (nj == 0 && d == 3) d = 2;
							if (nj == C - 1 && d == 2) d = 3;
							nj += dy[d];

						}
						if (a[i][j].siz > b[i][nj].siz)
							b[i][nj] = { a[i][j].speed, d, a[i][j].siz };
					}
					a[i][j] = { 0, 0, 0 };
				}
			}
		}
		memcpy(a, b, sizeof(b));
	}
}
int main() {
	scanf("%d%d%d", &R, &C, &M);
	for (int i = 0; i < M; i++) {
		int x, y, s, d, z;
		scanf("%d%d%d%d%d", &x, &y, &s, &d, &z);
		a[x - 1][y - 1] = { s, d - 1, z };
	}
	solve();
	printf("%d\n", ans);
	return 0;
}