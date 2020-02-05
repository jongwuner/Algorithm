#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, A, B, K, ans;
vector <ll> v, r;
int main() {
	scanf("%lld%lld%lld%lld", &N, &A, &B, &K);
	v.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &v[i]);
		r.push_back((v[i] - 1) % (A + B));
	}
	sort(r.begin(), r.end());
 
	for (int i = 0; i < N; i++) {
		K -= (r[i] / A);
		if (K < 0) break;
		ans++;
	}
	printf("%lld\n", ans);
	return 0;
}