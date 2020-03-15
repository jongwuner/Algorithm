#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pair;
int T, N;
Pair coin[10005];
int dp[105][10005];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> T >> N;
	for (int i = 1; i <= N; i++) 
		cin >> coin[i].first >> coin[i].second;
	
	sort(coin + 1, coin + N + 1);
	
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int k = 0; k <= coin[i].second; k++) {
			for (int j = 0; j <= T; j++) {
				if (j + coin[i].first * k > T) continue;
				dp[i][j + coin[i].first * k] += dp[i - 1][j];
			}
		}
	}
	cout << dp[N][T] << "\n";
	return 0;
}