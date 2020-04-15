#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 

	ll a1, a2, a, b, b1, b2, c, LCM;
	cin >> a1 >> a2 >> b1 >>b2;
	a = gcd(a1, a2);
	b = gcd(b1, b2);
	a1 = a1 / a;
	a2 = a2 / a;
	b1 = b1 / b;
	b2 = b2 / b;

	c = gcd(a2, b2);
	ll par = LCM = c * a2 / c * b2 / c;
	ll chi = a1 * LCM / a2 + b1 * LCM / b2;
	ll tmp = gcd(par, chi);
	par = par / tmp;
	chi = chi / tmp;
	cout << chi << " " << par << "\n";
	
	return 0;
}