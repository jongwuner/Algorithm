#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll N, pos;
ll curr = 0;
ll ans = 0;
ll lev = 0;
vector<pii> vi;
priority_queue<ll> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	cin >> N;
	vi.resize(N);
	for (ll i = 0; i < N; i++)
		cin >> vi[i].first;
	for (ll i = 0; i < N; i++)
		cin >> vi[i].second;
 
	sort(vi.begin(), vi.end());
 
	while (!pq.empty() || pos < N) {
		if (!pq.empty()) {
			curr -= pq.top();
			pq.pop();
			lev++;
			ans += curr;
		}
		else {
			lev = vi[pos].first;
		}
			
		while (pos < N && vi[pos].first == lev) {
			pq.push(vi[pos].second);
			curr += vi[pos].second;
			pos++;
		}
	}
	cout << ans << "\n";
	return 0;
}