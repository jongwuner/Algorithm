#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, A, B, GCD;
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int T; cin >> T; while (T--) {
		cin >> N;
		for (int i = 1; i * i <= N; i++) {
			if (N % i) continue;
			int tmp = N / i - 1;
			for (int j = 1; j * j <= tmp; j++) {
				if (tmp % j) continue;
				A = j;
				B = tmp / j;
				GCD = i;
				break;
			}
		}
		cout << GCD*A << " " << GCD*B << "\n";
	}
	return 0;
}