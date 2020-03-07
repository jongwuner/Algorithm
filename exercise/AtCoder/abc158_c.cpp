#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
double xa, xb, A, B;
bool visit[3];
bool ans = false;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> A >> B;
	for (double i = 1; i <= 100000000; i++) {
		double aa = floor(i * 0.08);
		double bb = floor(i * 0.1);
		if (aa == A && bb == B) {
			cout << (ll)i << "\n";
			ans = true;
			break;
		}
	}
	if (!ans) cout << "-1";
	return 0;
}
