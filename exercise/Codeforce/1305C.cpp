#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vl;
map<ll, ll> Map1;
ll N, M;
bool ans = true;
int main() {
	cin >> N >> M;
	vl.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> vl[i];
		if (Map1.find(vl[i]) != Map1.end()) {
			ans = false;
		}
		else Map1[vl[i]] = 1;
	}
	if (N >= M + 10) ans = false;
	ll res = 1;
	if (ans) {
		for (ll i = 0; i < N; i++) {
			for (ll j = i + 1; j < N; j++) {
				res *= abs(vl[i] - vl[j]);
				res %= M;
				if (res == 0) {
					ans = false;
					break;
				}
			}
			if (!ans) break;
		}
	}
 
	if (!ans) {
		cout << "0\n";
	}
	else cout << res << "\n";
	return 0;
}