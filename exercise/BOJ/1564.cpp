#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, ans = 1;
ll mod = 1e12;
ll mod2 = 100000;
int main() {
	scanf("%lld", &N);
	for (int i = 2; i <= N; i++) {
		ans *= i;
		while (ans % 10 == 0) ans /= 10;
		ans %= mod;
	}
	printf("%05lld\n", ans % mod2);
	return 0;
}