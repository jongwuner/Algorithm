#include<iostream>
using namespace std;
typedef long long ll;
ll N, M, ans, fact[250005] = {1, };
int main() {
	scanf("%lld%lld", &N, &M);
	for (int i = 1; i <= N; i++)
		fact[i] = fact[i - 1] * i % M;

	for (int i = 1; i <= N; i++) {
		ans += (N - i + 1) * (fact[i] * fact[N - i + 1] % M);
		ans %= M;
	}
	printf("%lld\n", ans);
	return 0;
}