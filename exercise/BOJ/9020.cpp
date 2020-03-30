#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int prime[15000];
vector<int> vl;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i < 15000; i++) prime[i] = i;
	for (ll i = 2; i * i < 15000; i++) {
		if (prime[i] == 0) continue;
		for (ll j = 2 * i; j < 15000; j+=i) {
			prime[j] = 0;
		}
	}
	for (int i = 1; i < 15000; i++) {
		if (prime[i]) vl.push_back(i);
	}
	
	int T; cin >> T; while (T--) {
		int L = 0; int R = vl.size() - 1;
		int ansL = 0, ansR = vl.size() - 1;

		int N; cin >> N;
		while (L <= R) {
			if (vl[L] + vl[R] < N)
				L++;
			else if (vl[L] + vl[R] > N)
				R--;
			else {
				ansL = L;
				ansR = R;
				L++; R--;
			}
		}
		cout << vl[ansL] << " " << vl[ansR] << "\n";
	}
	return 0;
}