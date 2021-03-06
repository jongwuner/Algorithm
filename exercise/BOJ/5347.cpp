#include<iostream>
using namespace std;
typedef long long ll;
int testCases;
ll uclid(ll a, ll b) {
	if (!b) return a;
	return uclid(b, a%b);
}

ll getAnswer(ll a, ll b) {
	ll t = uclid(a, b);
	return t * a / t * b / t;
}
int main() {
	scanf("%d", &testCases);
	while (testCases--) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", getAnswer(a, b));
	}
	return 0;
}