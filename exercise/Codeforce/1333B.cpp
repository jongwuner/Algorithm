#include<bits/stdc++.h>
using namespace std;
int N, M;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	int T; cin >> T; while (T--) {
		cin >> N;
		vector<int> A(N + 1);
		vector<int> B(N + 1);
		vector<int> visit(4);
		for (int i = 1; i <= N; i++) cin >> A[i];
		for (int i = 1; i <= N; i++) cin >> B[i];
 
		bool ans = true;
		for (int i = 1; i <= N; i++) {
			ans = false;
			if (A[i] < B[i] && visit[3]) {
				ans = true;
			}
			else if (A[i] == B[i]) {
				ans = true;
			}
			else if (A[i] > B[i] && visit[1]) {
				ans = true;
			}
			if (ans) visit[A[i] + 2] = true;
			else break;
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}