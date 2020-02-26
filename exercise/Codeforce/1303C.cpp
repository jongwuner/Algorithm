#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef long long ll;
int T;
vector<char> vc;
vector<bool> vb;
string S;
int main(){
    fast;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // clear
        S.clear();
        vc.clear();
        vb.clear();
        // init
        cin >> S;
        vc.resize(450);
        vb.resize(26);
        bool fg = true;
        int l = 200;
        int r = 200;
        int vidx = -1;
        int prev = -1;
        for (int i = 0; i < S.size(); i++) {
            bool isSearch = false;
            for (int j = 0; j < vc.size(); j++) {
                if (S[i] == vc[j]) {
                    prev = vidx;
                    vidx = j;
                    isSearch = true;
                    break;
                }
            }
            if (isSearch) {
                if (vidx == prev + 1 || vidx == prev - 1) continue;
                else {
                    fg = false;
                    break;
                }
            }
            else {
                if (vc[vidx + 1] == NULL) {
                    vc[r] = S[i];
                    vidx = r;
                    r++;
                }
                else if (vc[vidx - 1] == NULL) {
                    vc[l - 1] = S[i];
                    vidx = l - 1;
                    l--;
                }
                else {
                    fg = false;
                    break;
                }
            }
        }
        if (fg) {
            cout << "YES\n";
            for (int i = l; vc[i]; i++) {
                cout << vc[i];
                vb[vc[i] - 'a'] = true;
            }
            for (int i = 0; i < 26; i++)
                if (!vb[i]) cout << char(i + 'a');
            cout << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}