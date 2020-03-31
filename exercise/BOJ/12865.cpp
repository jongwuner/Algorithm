#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;
ll N, K, dp[105][100005];
Pair pr[105];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) 
		cin >> pr[i].first >> pr[i].second;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - pr[i].first < 0)
				dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - pr[i].first] + pr[i].second);
			}
		}
	}
	cout << dp[N][K] << "\n";
	return 0;
}