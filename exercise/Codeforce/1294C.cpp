#include<iostream>
using namespace std;
typedef long long ll;
int testCases;
ll N;
int main() {
	scanf("%d", &testCases);
	for (int tc = 1; tc <= testCases; tc++) {
		bool flag = false;
		scanf("%d", &N);
		for (ll i = 2; i * i <= N; i++) {
			if (N % i == 0 && i != N / i) {
				ll pdiv = N / i;
				for (ll j = i + 1; j * j <= N; j++) {
					ll ppp_div = pdiv / j;
					if (pdiv % j == 0 && j != ppp_div && ppp_div != i) {
						printf("YES\n");
						printf("%lld %lld %lld\n", i, j, pdiv / j);
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
		}
		if (!flag) printf("NO\n");
	}
	return 0;
}