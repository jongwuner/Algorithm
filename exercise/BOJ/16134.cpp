#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll fac[1000050] = {1, 1};
ll N, R;
ll qs(ll a, ll b) {
    if (b < 0) return 0;
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inv(int x) {
    return qs(x, mod - 2);
}
int C(int n, int m){
    ll ans = fac[n];
    ans = ans * inv(fac[m]) % mod;
    return ans * inv(fac[n - m]) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> R;
    ll MAXSIZE = max(N, R);
    for (int i = 2; i <= MAXSIZE; i++) fac[i] = fac[i - 1] * i % mod;
    cout << C(N, R) % mod << "\n";
    return 0;
}