#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll prime[260000];
ll mv;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i < 260000; i++) prime[i] = i;
	for (ll i = 2; i * i < 260000; i++) {
		if (prime[i] == 0) continue;
		for (ll j = 2 * i; j < 260000; j+=i) {
			prime[j] = 0;
		}
	}

	while (1) {
		int N; cin >> N;
		ll ans = 0;
		if (N == 0) break;
		for (int i = N + 1; i <= 2 * N; i++) {
			if (prime[i]) ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}