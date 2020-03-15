#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll segSize = 1, N, ans;
vector<ll> seg, vl;
void update(ll idx, ll val) {
	idx += segSize;
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
}
ll query(ll L, ll R, ll nodeIdx, ll nodeL, ll nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return seg[nodeIdx];
	ll mid = (nodeL + nodeR) / 2;
	return query(L, R, 2 * nodeIdx, nodeL, mid) + query(L, R, 2 * nodeIdx + 1, mid + 1, nodeR);
}
int main() {
	cin >> N;
	ll start = 0;
	ll end = N - 1;
	while (segSize < N) segSize = segSize << 1;
	seg.resize(segSize * 2);
	vl.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> vl[i];
	}
	for (ll i = N - 1; i >= 0; i--) {
    	ans += query(0, vl[i] - 2, 1, 0, segSize - 1);
		update(vl[i] - 1, 1);
	}
	
	cout << ans << "\n";
	return 0;
}