#include<iostream>
using namespace std;
typedef long long ll;
int main() {
	int testCases;
	scanf("%d", &testCases);
	while (testCases--) {
		ll N, M, p, q, peven = 0, podd = 0, qeven = 0, qodd = 0;
		scanf("%lld", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &p);
			if (p % 2 == 0) peven++;
			else podd++;
		}
		scanf("%lld", &M);
		for (int i = 1; i <= M; i++) {
			scanf("%lld", &q);
			if (q % 2 == 0) qeven++;
			else qodd++;
		}
		printf("%lld\n", peven * qeven + podd * qodd);
	}
	return 0;
}