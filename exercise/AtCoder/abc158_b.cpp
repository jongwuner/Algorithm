#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
ll N, A, B;
bool visit[3];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> A >> B;
	ll left = (N % (A + B) > A) ? A : (N % (A + B));
	cout << N / (A + B) * A + left << "\n";
}
