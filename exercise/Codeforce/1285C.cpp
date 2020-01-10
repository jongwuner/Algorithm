#include<iostream>
using namespace std;
typedef long long ll;
ll N, ans;
ll uclid(ll a, ll b) {
	if (b == 0) return a;
	return uclid(b, a % b);
}
int main() {
	scanf("%lld", &N);
	for (ll i = 1; i*i <= N; i++) {
		if (N % i == 0 && uclid(i, N/i)*i*N/i == N) {
			ans = i;
		}
	}
	printf("%lld %lld", ans, N / ans);
	return 0;
}