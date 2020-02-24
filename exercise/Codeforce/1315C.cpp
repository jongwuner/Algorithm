#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<int> vi;
vector<bool> chk;
bool ans;
int T, N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        //clear
        vi.clear();
        chk.clear();
        ans = true;
        //init
        cin >> N;
        vi.resize(N + 1);
        chk.resize(2 * N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> vi[i];
            chk[vi[i]] = true;
 
        }
        int val = 0;
        for (int i = 1; i <= 2 * N; i++) {
            if (chk[i]) {
                val++;
            }
            else val--;
            if (val < 0) {
                ans = false;
            }
        }
        if (!ans) {
            cout << "-1\n";
        }
        else {
            for (int i = 1; i <= N; i++) {
                cout << vi[i] << " ";
                for (int j = vi[i] + 1; j <= 2 * N; j++) {
                    if (!chk[j]) {
                        cout << j << " ";
                        chk[j] = true;
                        break;
                    }
                }
            }
            cout << "\n";
        }
    }
    return 0;
}