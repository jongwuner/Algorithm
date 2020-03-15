#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> a >> b >> c;
	ll x = c - a - b;
	if (x < 0) cout << "No\n";
	else if (4 * a * b < x * x) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
