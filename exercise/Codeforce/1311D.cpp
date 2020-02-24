#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, a, b, c;
struct num {
	int a, b, c;
};
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// clear
		int ans = 1e8;
		num ansStr = { 0, 0, 0 };
		// init
		cin >> a >> b >> c;
		for (int i = 1; i <= 2*1e4; i++) {
			for (int j = 1; j * j <= i; j++) {
				int A = j;
				int B = i;
				if (B % A == 0) {
					//int Cm = min(c % i, i - c % i);
					int Cm, C;
					if (c % i < i - c % i) {
						Cm = c % i;
						C = c - Cm;
					}
					else {
						Cm = i - c % i;
						C = c + Cm;
					}
 
					int Al, val;
					if (abs(A - a) < abs(B / A - a)) {
						val = abs(A - a) + abs(B - b) + Cm;
						A = j;
					}
					else {
						val = abs(B / A - a) + abs(B - b) + Cm;
						A = i / j;
					}
					if (ans > val) {
						ans = val;
						ansStr = { A, B, C };
					}
				}
			}
		}
		cout << ans << "\n";
		cout << ansStr.a << " " << ansStr.b << " " << ansStr.c << "\n";
	}
	return 0;
}