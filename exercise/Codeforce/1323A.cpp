#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, ans, dp[105][105], ecnt, ocnt, eIdx;
vector<ll> vl2;
vector<ll> vl;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	dp[1][0] = dp[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = dp[i][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < N; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
 
 
	int T; cin >> T; while (T--) {
		vl.clear();
		vl2.clear();
		ans = 0;
		ecnt = 0;
		ocnt = 0;
		eIdx = 0;
		
		cin >> N;
		vl.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> vl[i];
			if (vl[i] % 2 == 0) {
				ecnt++;
				eIdx = i;
			}
			if (vl[i] % 2 == 1) {
				ocnt++;
				vl2.push_back(i);
			}
		}
		if (ecnt) {
			cout << "1\n" << eIdx <<"\n";
		}
		else if(ocnt >= 2){
			cout << "2\n" << vl2[0] << " " << vl2[1] << "\n";
		}
		else {
			cout << "-1\n";
		}
	}
	return 0;
}