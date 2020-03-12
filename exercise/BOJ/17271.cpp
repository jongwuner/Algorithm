#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll n, m;
ll dp[10050] = { 1, 1 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (i >= m) dp[i] = (dp[i] + dp[i - m]) % mod;
	}
	cout << dp[n] << "\n";
	return 0;
}