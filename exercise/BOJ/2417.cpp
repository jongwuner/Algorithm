#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, ans;
int main() {
	scanf("%lld", &N);
	ans = ceil(sqrt(N));
	printf("%lld\n", ans);
	return 0;
}