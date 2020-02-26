#include <bits/stdc++.h>
using namespace std;
#define oo 1000000000
#define mod 998244853
const int N = 100010;

vector< pair< int, string > > v, v2;

int n, m, k, all = 0, cur;

string tmp;

void fix(vector< pair< int, string > >& v) {
    v2 = v;
    v.clear();
    for (int i = 0; i < (int)v2.size(); i++) {
        if (v2[i].first != 0)
            v.push_back(v2[i]);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        v.push_back(make_pair(m - 1, "R"));
        all += (v.back().first * (int)v.back().second.size());
        if (i == 1)
            v.push_back(make_pair(m - 1, "L"));
        else
            v.push_back(make_pair(m - 1, "UDL"));
        all += (v.back().first * (int)v.back().second.size());
        if (i == n)
            v.push_back(make_pair(n - 1, "U"));
        else
            v.push_back(make_pair(1, "D"));
        all += (v.back().first * (int)v.back().second.size());
    }
    if (all < k) {
        puts("NO");
        return 0;
    }
    while (all > k) {
        tmp = v.back().second;
        cur = (v.back().first * (int)v.back().second.size());
        v.pop_back();
        all -= cur;
        if (all >= k)
            continue;
        cur = k - all;
        if (cur / (int)tmp.size() > 0) v.push_back(make_pair(cur / (int)tmp.size(), tmp));
        tmp.resize(cur % (int)tmp.size());
        if ((int)tmp.size() > 0) v.push_back(make_pair(1, tmp));
        all = k;
    }
    puts("YES");
    fix(v);
    printf("%d\n", (int)v.size());
    for (int i = 0; i < (int)v.size(); i++) {
        printf("%d %s\n", v[i].first, v[i].second.c_str());
    }
    return 0;
}