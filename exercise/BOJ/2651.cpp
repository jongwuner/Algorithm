#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, N;
ll a[105], b[105], dp[105], pre[105];
stack<ll> S;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T >> N;
	for (ll i = 1; i <= N + 1; i++) {
		ll tmp;
		cin >> tmp;
		a[i] = a[i - 1] + tmp;
		// a[i] : [i - 1, i] 의 거리.
		dp[i] = -1;
	}
	// dp[i] : i까지 가는 최소 정비시간.

	for (ll i = 1; i <= N; i++)
		cin >> b[i];


	for (int i = 1; i <= N + 1; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] - a[j] > T) continue;
			if (dp[j] == -1) continue;
			if (dp[i] == -1 || dp[i] > dp[j] + b[i]) {
				dp[i] = dp[j] + b[i];
				pre[i] = j;
			}
		}
	}
	cout << dp[N + 1] << "\n";
	for (int i = pre[N + 1]; i > 0; i = pre[i])
		S.push(i);
	cout << S.size() << "\n";
	while (!S.empty()) {
		cout << S.top() << " ";
		S.pop();
	}
	cout << "\n";
	return 0;
}