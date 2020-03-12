#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans, N, minVal = 1e7;
vector<ll> vl;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T; cin >> T; while (T--) {
		vl.clear();
		bool ans = true;
		minVal = 1e7;
		
		cin >> N; vl.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> vl[i];
			if (minVal > vl[i]) minVal = vl[i];
		}
		for (int i = 1; i <= N; i++) {
			vl[i] -= minVal;
			if (vl[i] % 2) {
				ans = false;
				break;
			}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}