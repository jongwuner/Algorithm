#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K;
vector<ll> lis;
vector<bool> visit;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int T; cin >> T; while (T--) {
		lis.clear();
		visit.clear();
		bool ans = true;
 
		cin >> N >> K; lis.resize(N + 1); visit.resize(100);
		for (int i = 1; i <= N; i++) cin >> lis[i];
		for (int i = 1; i <= N; i++) {
			int cnt = -1;
			while (lis[i]) {
				if (lis[i] % K == 0) {
					lis[i] /= K;
					cnt++;
				}
				else if((lis[i] - 1) % K == 0) {
					lis[i] = (lis[i] - 1) / K;
					cnt++;
					if (visit[cnt]) {
						ans = false;
						break;
					}
					else visit[cnt] = true;
				}
				else {
					ans = false;
					break;
				}
			}
			if (!ans) break;
		}
		if (!ans) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}