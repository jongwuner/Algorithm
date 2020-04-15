#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll N, L;
	cin >> N >> L;
	for (ll i = L; i <= 100; i++) {
		if (i & 1) {
			// 홀수
			if (N % i == 0) {
				ll cnt = 1;
				ll j = N / i - (i / 2);
				if (j < 0) continue;
				for (j; cnt <= i; j++, cnt++) {
					cout << j <<" ";
				}
				return 0;
			}
		}
		else {
			// 짝수
			if ((N - i / 2) % i == 0) {
				ll cnt = 1;
				ll j = (N - i / 2) / i - (i / 2 - 1);
				if (j < 0) continue;
				for (j; cnt <= i; j++, cnt++) {
					cout << j << " ";
				}
				return 0;
			}
		}
	}
	cout << "-1\n";
	return 0;
}