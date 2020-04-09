#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll sum[250000], ans;
map<ll, ll> MAP;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	cin >> N;
	for (int i = 1; i <= N; i++) {
		ll tmp;
		cin >> tmp;
		sum[i] = sum[i - 1] + tmp;
	}
	ll val = -1;
	MAP[0] = 0;
	for (int i = 1; i <= N; i++) {
		if (MAP.find(sum[i]) != MAP.end()) {
			val = max(val, MAP[sum[i]]);
		}
		ans = ans + i - val - 1;
		MAP[sum[i]] = i;
	}
	cout << ans << "\n";
	return 0;
}