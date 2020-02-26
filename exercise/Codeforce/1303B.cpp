#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll N, G, B;
int main(){
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		//init
		ll ans;
		ll div;
		ll mod;
		scanf("%lld%lld%lld", &N, &G, &B);
		div = (N - 1) / 2 / G;
		mod = (N - 1) / 2 % G;
		ans = (G + B) * div + mod + 1;
		printf("%lld\n", (ans < N) ? N : ans);
	}
	return 0;
}