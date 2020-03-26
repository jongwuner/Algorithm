#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, dp[255][255], ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N; for (int i = 1; i <= N; i++) 
		cin >> dp[i][i], ans=max(ans, dp[i][i]);
	for (int i = 1; i < N; i++) {
		for(int j=1; j + i <= N; j++){
			for (int k = 1; k <= i; k++) {
				dp[j][j + i] = max(dp[j][j + i], (dp[j][j + k - 1] == dp[k + j][j + i]) ? dp[j][j + k - 1] + 1 : dp[j][j + i]);
				ans = max(ans, dp[j][j + i]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}