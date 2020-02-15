#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef long long ll;
int T;
ll x, y, a, b;
vector<char> vc;
vector<bool> vb;
string S;
int main(){
    fast;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> x >> y >> a >> b;
        if ((y - x) % (a + b) == 0) {
            cout << (y - x) / (a + b) << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}