#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
vector< vector<int> > vvi;
string s, t;
int pos, ans;
 
int main() {
	int T; cin >> T; while (T--) {
		// clear
		s.clear(); t.clear(); vvi.clear();
		pos = 0; ans = 1;
		// init
		cin >> s >> t;
		vvi.resize(s.size() + 1);
		for (int i = 0; i < s.size(); i++)
			vvi[i].resize(26, INF);
 
		for (int i = s.size() - 1; i >= 0; i--) {
			if(i < s.size() - 1)
				for (int j = 0; j < 26; j++)
					vvi[i][j] = vvi[i + 1][j];
			vvi[i][s[i] - 'a'] = i;
		}
		
		for (int i = 0; i < t.size(); i++) {
			if (pos == s.size()) {
				pos = 0;
				ans++;
			}
			if (vvi[pos][t[i] - 'a'] == INF) {
				pos = 0;
				ans++;
			}
			if (pos == 0 && vvi[pos][t[i] - 'a'] == INF) {
				ans = -1;
				break;
			}
 
			pos = vvi[pos][t[i] - 'a'] + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}