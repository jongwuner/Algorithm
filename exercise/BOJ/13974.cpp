#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, dp[5005][5005], opt[5005][5005];
vector<int> vl, sum;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		vl.clear();
		sum.clear();
		memset(dp, 0, sizeof(dp));
		memset(opt, 0, sizeof(opt));

		cin >> N;
		vl.resize(N + 1);
		sum.resize(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			cin >> vl[i];
			sum[i] = sum[i - 1] + vl[i];
			opt[i][i] = i;
		}

		for (int len = 1; len < N; len++) {
			for (int i = 1; i + len <= N; i++) {
				int tmp = 1e9;
				for(int k = opt[i][i + len - 1]; k <= opt[i + 1][i + len]; k++){
					if (tmp > dp[i][k] + dp[k + 1][i + len]) {
						tmp = dp[i][k] + dp[k + 1][i + len];
						opt[i][i + len] = k;
					}
				}
				dp[i][i + len] = tmp + sum[i + len] - sum[i - 1];
			}
		}
		cout << dp[1][N] << "\n";
	}
	return 0;
}