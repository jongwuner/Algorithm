#include<cstdio>
typedef long long ll;
int main() {
	ll n;

	while (scanf("%lld", &n), (n)) {
		ll a = 0;
		ll b = 0;
		int cnt = 1;
		// cnt odd : a
		// cnt even : b

		for (ll i = 1; i <= n; i = i << 1) {
			if ((n & i) == i) {
				if (cnt % 2 == 1) {
					// cnt odd : a
					a |= i;
					cnt++;
				}
				else {
					// cnt even : b
					b |= i;
					cnt++;
				}
			}
		}
		printf("%lld %lld\n", a, b);
	}
	return 0;
}