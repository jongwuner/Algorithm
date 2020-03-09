#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll ans, N;
ll mult[300005] = {1};
vector<ll> vl;
int main() {
	cin >> N; vl.resize(N + 1);
	for (int i = 1; i <= N; i++) cin >> vl[i];
	sort(vl.begin() + 1, vl.end());

	for (int i = 1; i <= N; i++) 
		mult[i] = (mult[i - 1] * 2) % MOD;
	for (int i = 1; i <= N; i++) {
		ans = (ans - ((mult[N - i] - 1) * vl[i] % MOD)) % MOD;
		ans = (ans + ((mult[i - 1] - 1) * vl[i] % MOD)) % MOD;
	}
	if (ans < 0) ans += MOD;
	cout << ans << "\n";
	return 0;
}