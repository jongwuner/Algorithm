#include<iostream>
using namespace std;
int N, L, a[105][105], ans;
void solved(int idx, bool opt) {
	// opt : 0 За
	// opt : 1 ї­
	int cnt = 1;
	for (int i = 1; i <= N - 1; i++) {
		int diff = (opt == 0) ? a[idx][i + 1] - a[idx][i] : a[i + 1][idx] - a[i][idx];

		if (diff == 0) cnt++;
		else if (diff == 1 && cnt >= L) cnt = 1;
		else if (diff == -1 && cnt >= 0) cnt = -L + 1;
		else return;
	}
	if (cnt >= 0) ans++;
}
int main() {
	scanf("%d%d", &N, &L);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= N; i++) {
		solved(i, 0);
		solved(i, 1);
	}
	printf("%d\n", ans);
	return 0;
}