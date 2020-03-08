#include<bits/stdc++.h>
using namespace std;
int N, M, K;
long long ans;
vector<int> via, vib, fac;
map<int, pair<int, int>> MAP;
int main() {
	cin >> N >> M >> K;
	via.resize(N + 1); vib.resize(M + 1);
	for (int i = 1; i <= N; i++) cin >> via[i];
	for (int i = 1; i <= M; i++) cin >> vib[i];
	for (int i = 1; i * i <= K; i++) {
		if (K % i) continue;
		int div = K / i;
		if (i != div) {
			fac.push_back(i);
			fac.push_back(div);
			MAP[i] = { 0, 0 };
			MAP[div] = { 0, 0 };
		}
		else {
			fac.push_back(i);
			MAP[i] = { 0, 0 };
		}
	}
 
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (via[i] == 1) cnt++;
		else {
			int t = 1;
			while (t <= cnt) {
				if (MAP.find(t) != MAP.end()) {
					MAP[t].first += cnt - t + 1;
				}
				t++;
			}
			cnt = 0;
		}
	}
	if (cnt != 0) {
		int t = 1;
		while (t <= cnt) {
			if (MAP.find(t) != MAP.end()) {
				MAP[t].first += cnt - t + 1;
			}
			t++;
		}
		cnt = 0;
	}
	
	for (int i = 1; i <= M; i++) {
		if (vib[i] == 1) cnt++;
		else {
			int t = 1;
			while (t <= cnt) {
				if (MAP.find(t) != MAP.end()) {
					MAP[t].second += cnt - t + 1;
				}
				t++;
			}
			cnt = 0;
		}
	}
	if (cnt != 0) {
		int t = 1;
		while (t <= cnt) {
			if (MAP.find(t) != MAP.end()) {
				MAP[t].second += cnt - t + 1;
			}
			t++;
		}
		cnt = 0;
	}
 
	for (auto now : fac) {
		ans += MAP[now].first * MAP[K / now].second;
	}
	cout << ans << "\n";
	return 0;
}