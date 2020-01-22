#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int testCases;
int main() {
    scanf("%d", &testCases);
    for (int tc = 1; tc <= testCases; tc++) {
        bool ans = true;
        ll a, b, c, n, maxVal = -123456789, pdiv = 0, res;
 
        scanf("%lld%lld%lld%lld", &a, &b, &c, &n);
        maxVal = max(a, b);
        maxVal = max(maxVal, c);
        pdiv += (maxVal - a);
        pdiv += (maxVal - b);
        pdiv += (maxVal - c);
 
        res = n - pdiv;
        if (pdiv > n) {
            ans = false;
            printf("NO\n");
        }
        else {
            if (res % 3 == 0) {
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }
    return 0;
}