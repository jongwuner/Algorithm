#include<iostream>
using namespace std;
typedef long long ll;
ll dp[1005][1005];
ll MOD = 1000000003;
int N, M;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= N; j++) 
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
	}

	printf("%lld\n", (dp[N - 3][M - 1] + dp[N - 1][M]) % MOD);
	return 0;
}