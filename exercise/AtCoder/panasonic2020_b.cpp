#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	ll a = ((M / 2 + M % 2) * (N / 2 + N % 2));
	ll b = (M / 2) * (N / 2);
	if (N == 1 || M == 1) {
		cout << "1\n" << "\n";
		return 0;
	}
	else cout << a + b << "\n";
	return 0;
}
