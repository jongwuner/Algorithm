#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
string S;
bool visit[3];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> S;

	for (int i = 0; i < 3; i++) {
		visit[S[i] - 'A'] = true;
	}
	bool fg = true;
	for (int i = 0; i < 2; i++) {
		if (!visit[i]) {
			fg = false;
			break;
		}
	}
	if (fg) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
