#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;
const int maxn = 5e5 + 10;
LL a[maxn];
vector<LL> p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    p.resize(maxn);
    stack<LL> s;
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[i] < a[s.top()]) {
            int t = s.top();
            s.pop();
            sum -= (t - (s.empty() ? -1 : s.top())) * a[t];
        }
        sum += (i - (s.empty() ? -1 : s.top())) * a[i];
        p[i] += sum;
        s.push(i);
    }
    while (!s.empty()) {
        s.pop();
    }
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[i] < a[s.top()]) {
            int t = s.top();
            s.pop();
            sum -= ((s.empty() ? n : s.top()) - t) * a[t];
        }
        sum += ((s.empty() ? n : s.top()) - i) * a[i];
        p[i] += sum - a[i];
        s.push(i);
    }
    int f = max_element(p.begin(), p.end()) - p.begin();
    for (int i = f - 1; i >= 0; i--) {
        a[i] = min(a[i], a[i + 1]);
    }
    for (int i = f + 1; i < n; i++) {
        a[i] = min(a[i], a[i - 1]);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}