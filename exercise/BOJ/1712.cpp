#include<iostream>
using namespace std;
typedef long long ll;
int main() {
	ll a, b, c, res = -1;
	scanf("%lld%lld%lld", &a, &b, &c);
	if (b < c) {
		res = a(c - b);
		res++;
	}
	printf(%lldn, res);
	return 0;
}