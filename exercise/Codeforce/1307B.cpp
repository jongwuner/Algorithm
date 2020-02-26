#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n;
double x, f;
set<double> s;
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// clear
		s.clear();
		f = 0;
 
		// init
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			double td;
			cin >> td;
			s.insert(td);
			f = max(f, td);
		}
		if (s.count(x)) {
			cout << "1\n";
		}
		else {
			cout << (ll)max(2.0, ceil(x / f))<<"\n";
		}
	}
	return 0;
}