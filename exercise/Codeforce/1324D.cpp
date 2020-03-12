#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 100;
int a[N];
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++){
        int num;
        cin >> num;
        a[i] -= num;
    }
    sort(a + 1, a + 1 + n);
    LL ans = 0;
    for (int i = 1; i <= n; i++){
        int pos = upper_bound(a + 1, a + i, -a[i]) - a;
        ans += i - pos;
    }
    cout << ans << "\n";
    return 0;
}