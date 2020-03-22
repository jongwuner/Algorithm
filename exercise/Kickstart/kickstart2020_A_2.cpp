#include<bits/stdc++.h>
using namespace std;
using lld = long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
int n, m, p;
lld a[109][109];
lld d[109][1509];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t; for (int tc = 1; tc <= t; tc++) {
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));

        cin >> n >> m >> p;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                a[i][j] += a[i][j - 1];
            }
            for (int j = 0; j <= p; j++) {
                d[i][j] = d[i - 1][j];
            }
            for (int j = 1; j <= p; j++) {
                for (int k = 1; k <= m && k <= j; k++) {
                    d[i][j] = max(d[i][j], d[i - 1][j - k] + a[i][k]);
                }
            }
        }
        cout << "Case #" << tc << ": " << d[n][p] << "\n";
    }
}