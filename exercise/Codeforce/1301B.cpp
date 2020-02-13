#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, N;
ll M;
bool fg;
vector<ll> v;
vector<ll> vm;
int main(){
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		// clear
		vm.clear();
		v.clear();
		fg = false;
		M = -1e5;
 
		// init
		scanf("%d", &N);
		v.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &v[i]);
		}
		for (int i = 1; i <= N; i++) {
			if (v[i] == -1) {
				if (i - 1 >= 1 && v[i - 1] != -1) vm.push_back(v[i - 1]);
				if (i + 1 <= N && v[i + 1] != -1) vm.push_back(v[i + 1]);
			}
		}
		sort(vm.begin(), vm.end());
		ll ans;
		if (vm.size()) {
			ans = (vm[0] + vm[vm.size() - 1]) / 2;
		}
		else ans = 0;
		
		for (int i = 2; i <= N; i++) {
			ll prev = v[i - 1];
			ll now = v[i];
			if (prev == -1 || now == -1) continue;
			M = max(M, abs(now - prev));
		}
 
		for (int i = 1; i <= N; i++) {
			if (v[i] == -1) {
				v[i] = ans;
			}
			if (i == 1) continue;
			M = max(M, abs(v[i] - v[i - 1]));
		}
		printf("%lld %lld\n", M, ans);
	}
	return 0;
}