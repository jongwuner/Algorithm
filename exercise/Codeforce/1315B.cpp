#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int T;
ll a, b, d, ans;
vector<pll> vpll, anspll;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // clear
        s.clear();
        vpll.clear();
       
        // init
        cin >> a >> b >> d >> s;
        int N = s.size();
        ans = N;
        char state = NULL;
        for (int i = 0; i < N - 1; i++) {
            if (state != s[i]) {
                state = s[i];
                if (state == 'A') {
                    vpll.push_back({ i + 1, a });
                }
                else if (state == 'B') {
                    vpll.push_back({ i + 1, b });
                }
            }
        }
        vpll.push_back({ N, 0 });
        for (int i = vpll.size() - 1; i >= 0; i--) {
            if (d - vpll[i].second >= 0) {
                ans = vpll[i].first;
                d -= vpll[i].second;
            }
            else break;
        }
        cout << ans << "\n";
    }
    return 0;
}