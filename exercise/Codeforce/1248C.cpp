#include <bits/stdc++.h>
using namespace std;
 
 
long long fib[1000010], n, m, mod = 1000000007, res;
int main() {
	cin >> n >> m;
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= 100000; i++) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	}
	res = ((fib[n] + fib[m] - 1) * 2) % mod;
 
	cout << res << endl;
	return 0;
}