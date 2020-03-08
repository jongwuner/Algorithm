#include<bits/stdc++.h>
using namespace std;
int N, cnt, ans;
string S;
vector<int> vi;
int main() {
	cin >> N >> S;
	if (N & 1) {
		cout << "-1\n";
		return 0;
	}
	vi.resize(N);
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') cnt++;
	}
	if (cnt != N / 2) {
		cout << "-1\n";
		return 0;
	}
	cnt = 0;
	int prev = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') cnt = prev + 1;
		else if (S[i] == ')') cnt = prev - 1;
 
		if (cnt < 0 || cnt == 0 && prev < 0)
			ans++;
		prev = cnt;
	}
	cout << ans << "\n";
	return 0;
}