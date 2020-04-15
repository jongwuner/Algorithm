#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> Map;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll N;
	cin >> N; 
	vector<ll> vi1(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> vi1[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Map.find(abs(vi1[i] - vi1[j])) != Map.end()) {
				continue;
			}
			else Map[abs(vi1[i] - vi1[j])] = 1;
		}
	}
	map<ll, ll>::iterator it = Map.begin();
	ll g = it->first;
	for (it; it != Map.end(); it++) {
		g = gcd(g, it->first);
	}

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (int i = 1; i * i <= g; i++) {
		if (i == 1) {
			pq.push(g);
			continue;
		}
		if (g % i != 0) continue;
		if (g / i == i) {
			pq.push(i);
			continue;
		}
		pq.push(i);
		pq.push(g / i);
	}
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << "\n";
	return 0;
}