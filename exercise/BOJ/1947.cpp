#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000000;
ll N, dp[1000055] = {0, 0, 1};
int main() {
	cin >> N;
	for (int i = 3; i <= N; i++) 
		dp[i] = (i - 1) * ((dp[i - 1] + dp[i - 2]) % mod) % mod;
	cout << dp[N] << "\n";
	return 0;
}