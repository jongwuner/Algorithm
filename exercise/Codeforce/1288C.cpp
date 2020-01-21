#include<iostream>
using namespace std;
typedef long long ll;
ll N, M, dp[1505][1505] = {1, }, MOD = 1000000007;


int main() {
	for (int i = 1; i <= 1500; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j <= 1500; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	scanf("%lld%lld", &N, &M);
	printf("%lld", dp[N+2*M-1][2*M]);
	return 0;
}