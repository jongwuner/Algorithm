#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T; while (T--) {
		int N, ans = 1, cnt = 0; 
		cin >> N;
		map<string, int> Map;
		for (int i = 1; i <= N; i++) {
			string name, kind;
			cin >> name >> kind;
			if (Map.find(kind) != Map.end()) {
				Map[kind]++;
			}
			else Map[kind] = 1;
		}
		for (map<string, int>::iterator it = Map.begin(); it != Map.end(); it++) {
			ans *= (it->second + 1);
		}
		ans--;
		cout << ans << "\n";
		
	}
	return 0;
}