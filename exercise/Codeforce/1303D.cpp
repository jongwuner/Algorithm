#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int M;
ll N, ans;
vector<ll> vl;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		// clear
		ans = 0;
		vl.clear();
		// init
		int tmp;
		cin >> N >> M;
		for (int i = 0; i < M; i++) cin >> tmp, vl.push_back(tmp);

		sort(vl.begin(), vl.end());

		ll nptr = 1;
		ll sum = 0;
		int idx = 0;
		while (idx < M && N) {
			while ((N & nptr) != nptr) 
				nptr = nptr << 1;

			while (idx < M && sum < nptr) 
				sum += vl[idx], idx++;

			if (idx >= M && sum < nptr) break;

			ll nlsb = 1, slsb = 1;
			while (N >= nlsb) nlsb = nlsb << 1; nlsb = nlsb >> 1;
			while (sum >= slsb) slsb = slsb << 1; slsb = slsb >> 1;


			ll cnt = 0;
			if (slsb == nptr) {
				sum = sum >> cnt;
				sum -= nptr;
				N = (N | slsb) - slsb;
				ans += cnt;
			}
			else {
				while ((slsb & nptr) != nptr) {
					cnt++;
					slsb = slsb >> 1;
					N = (N | slsb) - slsb;
				}
				sum = sum >> cnt;
				sum -= nptr;
				N = (N | slsb) - slsb;
				ans += cnt;
			}
		}
		if (N) ans = -1;
		cout << ans << "\n";
	}
	return 0;
}