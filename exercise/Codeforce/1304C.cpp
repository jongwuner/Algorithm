#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef long long ll;
int N, M, T;
ll t, l, h;
struct People {
    ll t, l, h;
};
vector<People> vp;
int main(){
    fast;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        //c lear
        vp.clear();
 
        //init
        bool fg = true;
        cin >> N >> M;
        People now = {0, M, M};
        for (int i = 0; i < N; i++) {
            cin >> t >> l >> h;
            vp.push_back({ t, l, h });
        }
        for (int i = 0; i < N; i++) {
            ll diff = vp[i].t - now.t;
            ll L = now.l - diff;
            ll R = now.h + diff;
 
            if (L <= vp[i].l && vp[i].l <= R && L <= vp[i].h && vp[i].h <= R) {
                now.t = vp[i].t;
                now.l = vp[i].l;
                now.h = vp[i].h;
            }
            else if (L < vp[i].l && vp[i].l <= R && R <= vp[i].h) {
                now.t = vp[i].t;
                now.l = vp[i].l;
                now.h = R;
            }
            else if (vp[i].h < R && vp[i].l <= L && L <= vp[i].h) {
                now.t = vp[i].t;
                now.l = L;
                now.h = vp[i].h;
            }
            else if(vp[i].l <=L && R <= vp[i].h){
                now.t = vp[i].t;
                now.l = L;
                now.h = R;
            }
            else {
                fg = false;
                break;
            }
        }
        if (fg) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}