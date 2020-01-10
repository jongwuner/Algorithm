
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int testCases;
int main() {
	scanf("%d", &testCases);
	for (int tc = 1, N; tc <= testCases; tc++) {
		ll sum = 0;
		ll t, tsum = 0, maxVal = -1e18;
		scanf("%d", &N);
		int s = 1, e = N;
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &t);
			sum += t;
			if (tsum + t > 0) {
				tsum += t;
				e = i;
			}
			else {
				tsum = 0;
				s = i + 1;
			}
			if(s != 1 || e != N)
				maxVal = max(maxVal, tsum);
		}
		if (maxVal >= tsum) {
			printf("NO\n");
		}
		else printf("YES\n");
	}
	return 0;
}