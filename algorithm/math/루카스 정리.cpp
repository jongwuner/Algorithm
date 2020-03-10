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

// https://blog.naver.com/rym/220833779518