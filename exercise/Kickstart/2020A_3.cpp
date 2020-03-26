#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;
typedef pair<ll, Pair> PPair;
ll T, N, K;
vector<ll> vl;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T; for (int tc = 1; tc <= T; tc++) {
		priority_queue<PPair> pq;
		vl.clear();

		cin >> N >> K; vl.resize(N + 1);
		for (int i = 1; i <= N; i++) 
			cin >> vl[i];
		
		for (int i = 1; i <= N - 1; i++) 
			pq.push({ vl[i + 1] - vl[i], {vl[i + 1] - vl[i], 1 } });
	

		for (int i = 1; i <= K; i++) {
			PPair now = pq.top(); pq.pop();
			now.second.second++;

			ll add = (now.second.first % now.second.second) ? 1 : 0;
			ll val = now.second.first / now.second.second + add;
			now.first = val;
			pq.push(now);
		}
		cout << "Case #" << tc << ": " << pq.top().first << "\n";
	}
	return 0;
}