#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int testCases, N;
ll dp[35][35];
ll getAnswer(int r, int c) {
	if (r == 0) return 1;
	if (r > c) return 0;

	ll& ret = dp[r][c];
	if (ret != -1) return ret;

	ret = 0;
	if (r == c) ret = getAnswer(r - 1, c);
	else ret = (getAnswer(r - 1, c) + getAnswer(r, c - 1));
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	for (int tc = 1; ; tc++) {
		scanf("%d", &N);
		if (!N) break;
		printf("%lld\n", getAnswer(N, N));
	}
	return 0;
}