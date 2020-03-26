#include<bits/stdc++.h>
using namespace std;
int Ssize, ans = -1e9; string S;
int cal(int a, int b, char opt) {
	if (opt == '+') return a + b;
	if (opt == '-') return a - b;
	if (opt == '*') return a * b;
}
void getAnswer(int lev, int val) {
	if (lev == Ssize - 1) {
		ans = max(ans, val);
		return;
	}

	int v1, v2;
	v1 = cal(val, S[lev + 2] - '0', S[lev + 1]);
	getAnswer(lev + 2, v1);

	if (lev + 4 < Ssize) {
		v2 = cal(S[lev + 2] - '0', S[lev + 4] - '0', S[lev + 3]);
		v2 = cal(val, v2, S[lev + 1]);
		getAnswer(lev + 4, v2);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> Ssize >> S;
	getAnswer(0, S[0] - '0');
	cout << ans << "\n";
	return 0;
}