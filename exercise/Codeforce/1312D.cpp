#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const ll MAX = 200010;
ll N, M, fac[MAX] = {1, 1};
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
int C(int n, int m)
{
    ll ans = fac[n];
    ans = ans * inv(fac[m]) % mod;
    return ans * inv(fac[n - m]) % mod;
}
int main() {
    cin >> N >> M;
    for (int i = 2; i <= max(N, M); i++) fac[i] = fac[i - 1] * i % mod;
    cout << C(M, N - 1) * (N - 2) % mod * qs(2, N - 3) % mod <<"\n";
    return 0;
}