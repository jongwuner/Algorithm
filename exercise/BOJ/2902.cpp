#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string S, ans; cin >> S;
	ans += S[0];
	for (int i = 1; i < S.size(); i++) {
		if (S[i] == '-') {
			ans += S[i + 1];
			i++;
		}
	}
	cout << ans << "\n";
	return 0;
}