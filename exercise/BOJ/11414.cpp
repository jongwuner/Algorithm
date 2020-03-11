#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B, X, tk, tRes, res = 1e18, ans, tAns;
vector<ll> vl;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> A >> B;
	if (B > A) swap(A, B);
	else if (A == B) {
		cout << "1\n";
		return 0;
	}
	ans = X = A - B;
	for (ll i = 1; i * i <= X; i++) {
		if (X % i) continue;
		vl.push_back(i);
		if (X / i != i)
			vl.push_back(X / i);
	}
	for (ll v : vl) {
		if (A % v) {
			tk = v - A % v;
		}
		else continue;
		ll tgcd = gcd(A + tk, B + tk);
		ll tRes = tgcd * (A + tk) / tgcd * (B + tk) / tgcd;
		if (res > tRes) {
			res = tRes;
			ans = tk;
		}
		else if (res == tRes) {
			ans = min(ans, tk);
		}
	}
	cout << ans << "\n";
	return 0;
}