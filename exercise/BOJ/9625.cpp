#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;
int N;
Pair fibo[50] = { {1, 0}, {0, 1} };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 2; i <= N; i++) {
		fibo[i].first = fibo[i - 1].first + fibo[i - 2].first;
		fibo[i].second = fibo[i - 1].second + fibo[i - 2].second;
	}
	cout << fibo[N].first << " " << fibo[N].second << "\n";
	return 0;
}