#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double a, b;
	scanf("%lf%lf", &a, &b);
	int aa = (int)ceil(sqrt(a));
	int bb = (int)floor(sqrt(b));
	int ans = 0;
	for (int k = aa; k <= bb; k++) {
		ans += (k * k);
	}
	if (!ans) printf("%d\n", -1);
	else printf("%d\n%d\n", ans, aa*aa);
	return 0;
}