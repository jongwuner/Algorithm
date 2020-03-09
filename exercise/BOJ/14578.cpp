#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 50;
ll MOD = 1000000007;
ll facto[MAX] = { 1, 1, 2 };
ll N, dp[MAX] = { 0, 0, 1 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 3; i <= N; i++) {
		facto[i] = i * facto[i - 1] % MOD;

		ll sum = (dp[i - 1] + dp[i - 2]) % MOD;
		dp[i] = (i - 1) * sum % MOD;
	}
	cout << facto[N] * dp[N] % MOD<<"\n";
	return 0;
}