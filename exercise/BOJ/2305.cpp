#include<iostream>
using namespace std;
int N, K, fibo[45] = { 1,1,2 }, dp[45] = { 0, 0, 2, 6 }, ans;
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 3; i < 45; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
	for (int i = 4; i <= 41; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		for (int j = i - 1; j > 0; j--)
			dp[i] += fibo[j];
	}
	if (K == 1 || K == N)
		ans = dp[K] * fibo[N - K] + dp[N - K + 1] * fibo[K - 1];
	else
		ans = dp[K] * fibo[N - K] + dp[N - K + 1] * fibo[K - 1] - fibo[K - 1] * fibo[N - K];
	printf("%d\n", ans);
	return 0;
}