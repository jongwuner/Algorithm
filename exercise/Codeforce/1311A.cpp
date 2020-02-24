#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, N, a, b;
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> a >> b;
		if (a == b) {
			cout << "0\n";
		}
		else if (a % 2 == 1 && b % 2 == 1) {
			if (a > b) cout << "1\n";
			else cout << "2\n";
		}
		else if (a%2 == 0 && b % 2 == 1) {
			if (a > b) cout << "2\n";
			else cout << "1\n";
		}
		else if (a%2 == 1&& b % 2 == 0) {
			if (a > b) cout << "2\n";
			else cout << "1\n";
		}
		else if (a % 2 == 0 && b % 2 == 0) {
			if (a > b) cout << "1\n";
			else cout << "2\n";
		}
	}
	return 0;
}