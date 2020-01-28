#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int T, N;
vector<ll> V;
ll sum, xsum;
int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		//clear
		V.clear();
		sum = 0;
		xsum = 0;

		//init
		scanf("%d", &N);
		V.resize(N + 1);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &V[i]);
			sum += V[i];
			xsum ^= V[i];
		}

		if (sum == xsum * 2) {
			printf("0\n\n");
		}
		else if (xsum == 0) {
			printf("1\n%lld\n", sum);
		}
		else {
			printf("2\n%lld %lld\n", xsum, xsum + sum);
		}
	}
	return 0;
}