#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, M;
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}
ll phi(ll n) {
	ll res = n;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i) continue;
		res -= res / i;
		while (n % i == 0)
			n /= i;
	}
	if (n > 1)
		res -= res / n;
	return res;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		cin >> A >> M;
		ll G = gcd(A, M);
		ll M2 = M / G;
		cout << phi(M2) << "\n";
	}
	return 0;
}