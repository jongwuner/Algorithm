#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	vector<ll> vl1, vl2;
	ll N, cnt1 = 0, cnt2 = 0,  ans = 1;
	bool fg = false;
	cin >> N;
	vl1.resize(N + 1);
	vl2.resize(N + 1);
	for (ll i = 1; i <= N; i++) {
		cin >> vl1[i];
	}
	for (ll i = 1; i <= N; i++) {
		cin >> vl2[i];
		if (vl1[i] == 1 && vl2[i] == 0) cnt1++;
		if (vl1[i] == 0 && vl2[i] == 1) cnt2++;
	}
	for (ll i = 1; i <= N; i++) {
		if (i * cnt1 > cnt2) {
			fg = true;
			ans = i;
			break;
		}
	}
	if (fg == false) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}