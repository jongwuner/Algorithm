#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> lis;
int N;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int T; cin >> T; while (T--) {
		lis.clear();
 
		cin >> N;
		lis.resize(N + 1);
		for (int i = 1; i <= N; i++) cin >> lis[i];
		sort(lis.begin() + 1, lis.end());
		for (int i = lis.size() - 1; i >= 1; i--)
			cout << lis[i] <<" ";
		cout << "\n";
	}
	return 0;
}