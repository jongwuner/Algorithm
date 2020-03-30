#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		ll A, B, N = 0, add = 0;
		cin >> A >> B;
		while (N * (N + 1) < B - A) {
			N++;
		}
		if (N * (N - 1) + N < B - A) {
			add+=2;
		}
		else {
			add++;
		}
		N--;
		cout << 2*N + add<< "\n";
	}
	return 0;
}