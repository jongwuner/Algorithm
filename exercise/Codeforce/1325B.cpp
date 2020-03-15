#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, A, B, GCD;
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int T; cin >> T; while (T--) {
		vector<int> vi;
		map<int, int> mi;
		int ans = 0;
 
		cin >> N;
		vi.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> vi[i];
		}
		for (int i = 1; i <= N; i++) {
			if (mi.find(vi[i]) == mi.end()) {
				mi[vi[i]] = 1;
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}