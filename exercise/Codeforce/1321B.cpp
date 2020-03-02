#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll > Pair;
int N;
ll ans = -1e8;
map<ll, ll> M;
vector<ll> vl;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	vl.resize(N + 1);
	for (int i = 0; i < N; i++)
		cin >> vl[i];

	for (int i = 0; i < N; i++) {
		if (M.find(vl[i] - i) == M.end()) {
			M[vl[i] - i] = vl[i];
			ans = max(ans, M[vl[i] - i]);
		}
		else {
			M[vl[i] - i] += vl[i];
			ans = max(ans, M[vl[i] - i]);
		}
	}
	cout << ans << "\n";
	return 0;
}