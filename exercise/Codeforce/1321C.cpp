#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char a[105];
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> a + 1;
    int rn = n;
    for (char i = 'z'; i > 'a'; i--) { 
        for (int go = 1; go <= 100; go++) {
            for (int j = 1; j <= n; j++) { 
                if (a[j] == i && (a[j - 1] == i - 1 || a[j + 1] == i - 1)) {
                    for (int k = j; k < n; k++) a[k] = a[k + 1];
                    a[n] = '!';
                    n--;
                    j--;
                }
            }
        }
    }
    cout << rn - n << '\n';
}