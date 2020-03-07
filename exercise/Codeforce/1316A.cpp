#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vl;
ll N, M, sum, tsum;
int main() {
	int T; cin >> T; while (T--) {
		sum = tsum = 0;
		vl.clear();
 
		cin >> N >> M;
		vl.resize(N + 1);
		for (ll i = 1; i <= N; i++) {
			cin >> vl[i];
			if(i > 1) tsum += vl[i];
		}
		if (vl[1] + tsum >= M) cout << M << "\n";
		else cout << vl[1] + tsum << "\n";
	}
	return 0;
}
