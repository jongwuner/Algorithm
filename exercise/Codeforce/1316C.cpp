#include<bits/stdc++.h>
using namespace std;
int n, m, p, ans;
vector<int> a, b;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> p;
	a.resize(n); b.resize(m);
	bool fg = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] %= p;
		if (!fg && a[i]) {
			fg = true;
			ans += i;
		}
	}
	fg = false;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		b[i] %= p;
		if (!fg && b[i]) {
			fg = true;
			ans += i;
		}
	}
	cout << ans << "\n";
	return 0;
}