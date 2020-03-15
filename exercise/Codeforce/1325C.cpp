#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int N, cnt, Rcnt;
int ea[MAX], eb[MAX], num[MAX];
vector<vector<int>> adj;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	cin >> N;
	adj.resize(N + 1); 
	for (int i = 1; i <= N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		ea[i] = a;
		eb[i] = b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	Rcnt = N - 2;
	for (int i = 1; i <= N - 1; i++) {
		int A = ea[i];
		int B = eb[i];
		if (adj[A].size() == 1 || adj[B].size() == 1) {
			cout << cnt++ << "\n";
		}
		else {
			cout << Rcnt-- << "\n";
		}
	}
	return 0;
}