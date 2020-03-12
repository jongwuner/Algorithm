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
		string S; cin >> S;
		int N = S.size();
		int ans = -1e8;
		int prev = -1;
		for (int i = 0; i <= N; i++) {
			if (S[i] == 'R' || i == N) {
				ans = max(ans, i - prev);
				prev = i;
			}
		}
		cout << ans << "\n";
 
	}
	return 0;
}