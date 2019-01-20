#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define MAX_LEN 21
using namespace std;
typedef long long ll;
int main() {
	ll N, M, ans = 0;
	vector< vector<ll> > list;
	scanf("%lld%lld", &N,&M);
	list.resize(MAX_LEN);
	for (ll i = 1; i <= N; i++) {
		string s; cin >> s;
		list[s.size()].push_back(i);
	}
	for (ll i = 1; i <= 20; i++) {
		sort(list[i].begin(), list[i].end());
		for (ll j = 0; j < list[i].size(); j++) {
			ll idx = upper_bound(list[i].begin() + j, list[i].end(), list[i][j] + M) - (list[i].begin() + j);
			ans += (idx - 1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}