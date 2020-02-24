#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll a, b, x, y;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // clear
        ll lis[5];
        ll ans = -1e8;
 
        // init
        cin >> a >> b >> x >> y;
        lis[0] = a * y;
        lis[1] = x * b;
        lis[2] = (a - x - 1) * b;
        lis[3] = a * (b - y - 1);
        for (int i = 0; i <= 3; i++) {
            ans = max(ans, lis[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}