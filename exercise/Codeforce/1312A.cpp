#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int N, M;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int T; cin >> T; while (T--) {
		cin >> N >> M;
		if (N % M == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}