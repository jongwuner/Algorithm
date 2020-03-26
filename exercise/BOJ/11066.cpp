#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, dp[550][550];
vector<ll> vl, sum;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		vl.clear(); 
		sum.clear();
		memset(dp, 0, sizeof(dp));

		cin >> N; 
		vl.resize(N + 1); 
		sum.resize(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			cin >> vl[i];
			sum[i] = sum[i - 1] + vl[i];
		}

		for (ll len = 1; len < N; len++) {
			for (ll i = 1; i + len <= N; i++) {
				ll tmp = 1e17;
				for (ll mid = 1; mid <= len; mid++) {
					tmp = min(tmp, dp[i][i + mid - 1] + dp[i + mid][i + len]);
				}
				dp[i][i + len] = tmp + sum[i + len] - sum[i - 1];
			}
		}
		cout << dp[1][N] << "\n";
	}
	return 0;
}