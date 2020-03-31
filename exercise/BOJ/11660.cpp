#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M;
ll board[1050][1050], dp[1050][1050];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> board[i][j];
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] + board[i][j] - dp[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1] << "\n";
	}
	return 0;
}