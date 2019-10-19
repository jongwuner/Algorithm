#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll getanswer(ll num, ll times) {
	if (times == 1) return num;

	ll answer = getanswer(num, times / 2);
	if (times % 2 == 0) return answer * answer % MOD;
	else return num * answer % MOD * answer % MOD;
}
int main() {
	ll n, m, ans = 1;
	scanf("%lld%lld", &n, &m);
	ans = getanswer(2, m);
	ans = (ans - 1) % MOD;
	ans = getanswer(ans, n);
	printf("%lld\n", ans);
	return 0;
}