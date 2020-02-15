#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef long long ll;
int n, m, cnt=0;
vector<string> vs1; // 팰린
vector<string> vs2; // rev
vector<int> viansidx;
vector<int> vi;
bool isParlin(string ts) {
    int len = ts.size() - 1;
    for (int i = 0; i <= len / 2; i++) {
        if (ts[i] != ts[len - i])
            return false;
    }
    return true;
}
int main(){
    fast;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string ts;
        cin >> ts;
        if (isParlin(ts)) 
            vs1.push_back(ts);
     
        else 
            vs2.push_back(ts);
        
    }
    sort(vs2.begin(), vs2.end());
    for (int i = 0; i < vs2.size(); i++) {
        string rs = vs2[i];
        reverse(rs.begin(), rs.end());
        for (int j = i + 1; j < vs2.size(); j++) {
            if (vs2[j] == rs) {
                viansidx.push_back(i);
            }
        }
    }
    int revNum = 2 * viansidx.size();
    int parlNum = vs1.size();
    if (viansidx.size() >= 1) {
        
        //cout << 2 * viansidx.size() * m + m << "\n";
        if (parlNum >= 1) {
            cout << 2 * viansidx.size() * m + m << "\n";
        }
        else {
            cout << 2 * viansidx.size() * m<<"\n";
        }
 
        for (int i = 0; i < viansidx.size(); i++) {
            int idx = viansidx[i];
            cout << vs2[idx];
        }
        if (vs1.size() >= 1) {
            
            cout << vs1[0];
 
        }
 
        for (int i = viansidx.size() - 1; i >= 0; i--) {
            int idx = viansidx[i];
            string ts = vs2[idx];
            reverse(ts.begin(), ts.end());
            cout << ts;
        }
    }
    else if (vs1.size() >= 1) {
        cout << m << "\n";
        cout << vs1[0] << "\n";
    }
    else {
        cout << "0\n";
    }
    return 0;
}