#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, N, B, ans;
vector<ll> vl;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T; for(int tc=1; tc<=T; tc++) {
		ans = 0;
		vl.clear();

		cin >> N >> B; vl.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> vl[i];
		}
		sort(vl.begin() + 1, vl.end());
		for (int i = 1; i <= N; i++) {
			if (B - vl[i] < 0) break;
			B -= vl[i];
			ans++;
		}
		cout << "Case #"<<tc <<": "<< ans << "\n";
	}
	return 0;
}