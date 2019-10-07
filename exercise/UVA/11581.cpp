#include<cstdio>
#include<cstring>
int g[3][3];

bool iskgh() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (g[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void trans() {
	int h[3][3];
	const int mvI[4] = {1, 0, -1, 0};
	const int mvJ[4] = {0, -1, 0, 1};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int tmp = 0;
			for (int k = 0; k < 4; k++) {
				int nextI = i + mvI[k];
				int nextJ = j + mvJ[k];
				if (nextI < 0 || nextI > 2 || nextJ < 0 || nextJ > 2) continue;
				tmp = (tmp + g[nextI][nextJ]) % 2;
			}
			h[i][j] = tmp;
		}
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			g[i][j] = h[i][j];
	return;
}

int main() {
	int testCases;

	scanf("%d", &testCases);
	while (testCases--) {
		int ans = -1;
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%1d", &g[i][j]);
			}
		}
		while (!iskgh()) {
			ans++;
			trans();
		}
		printf("%d\n", ans);
	}
	return 0;
}