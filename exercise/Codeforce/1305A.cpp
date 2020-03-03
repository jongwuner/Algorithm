#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
vector<ll> v1, v2;
int main() {
	int T; cin >> T; while (T--) {
		v1.clear(); v2.clear();
		cin >> N;
		v1.resize(N); v2.resize(N);
		for (int i = 0; i < N; i++) cin >> v1[i];
		for (int i = 0; i < N; i++) cin >> v2[i];
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		for (int i = 0; i < N; i++) 
			cout << v1[i] << " ";
		cout << "\n";
		for (int i = 0; i < N; i++)
			cout << v2[i] << " ";
		cout << "\n";
 
	}
	return 0;
}