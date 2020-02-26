#include<bits/stdc++.h>
using namespace std;
int n, x, y;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;  cin >> T; while (T--) {
		cin >> n >> x >> y;
		int minVal = (x + y < n) ? 1 : min(n, x + y - n + 1);
		cout << minVal << " " <<min(n, x + y - 1);
		cout << "\n";
	}
	return 0;
}