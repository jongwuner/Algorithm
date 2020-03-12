#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pair;
const int MAX = 5001;
map<int, int> Map;
vector<int> vi;
int N;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T; cin >> T; while (T--) {
		vi.clear();
		Map.clear();
		bool ans = false;
 
		cin >> N;
		vi.resize(N + 1);
		for (int i = 1; i <= N; i++) 
			cin >> vi[i];
		for (int i = 1; i <= N; i++) {
			if (Map.find(vi[i]) == Map.end()) {
				Map[vi[i]] = i;
			}
			else {
				if (i - Map[vi[i]] >= 2) {
					ans = true;
					break;
				}
			}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
 
 
	}
	return 0;
}