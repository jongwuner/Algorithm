#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAX = 405;
ll dp[MAX][MAX], a[MAX], N, K, maxVal[MAX][MAX], sum[MAX];
int main() {
	scanf("%lld%lld", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + a[i];
		ll val = a[i];
		for (int j = i; j <= N; j++) {
			val = max(val, a[j]);
			maxVal[i][j] = val;
		}
	}
	for (int i = 1; i <= N; i++) {
		dp[i][0] = i * maxVal[1][i] - sum[i];
	}
	for (int j = 1; j <= K; j++) {
		for (int i = j+1; i <= N; i++) {
			if (i == j + 1) {
				dp[i][j] = 0;
				continue;
			}
			ll val = 1e17;
			for (int k = 1; k <= i - 1; k++) {
				val = min(val, dp[i - k][j - 1] + k * maxVal[i - k + 1][i] - (sum[i] - sum[i - k]));
			}
			dp[i][j] = val;
		}
	}
	printf("%lld\n", dp[N][K]);
	return 0;
}