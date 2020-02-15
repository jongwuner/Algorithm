#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll n, p, w, d;
int main(){
    bool fg = false;
    ll n, p, w, d;
    scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
    for (ll y = 0; y < w; y++) {
        ll yd = y * d;
        ll xw = p - yd;
        
        if ((xw % w == 0) && ((xw / w) + y <= n) && xw / w >= 0) {
            ll x = xw / w;
            printf("%lld %lld %lld\n", x, y, n - (x + y));
            fg = true;
            break;
        }
    }
    if (!fg) printf("-1\n");
    return 0;
}