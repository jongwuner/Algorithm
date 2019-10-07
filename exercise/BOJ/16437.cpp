#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

vector< vector<int> > adj;
vector<char> kind;
vector<ll> numOfAni;

ll postSearch(int idx) {
	ll sum = 0;
	for (int next : adj[idx]) {
		sum += postSearch(next);
	}
	if (kind[idx] == 'S') return numOfAni[idx] + sum;
	else 
		return (sum - numOfAni[idx] >= 0) ? sum - numOfAni[idx] : 0;
}
int main() {
	int N;
	scanf("%d", &N);
	
	adj.resize(N + 1);
	kind.resize(N + 1);
	numOfAni.resize(N + 1);
	for (int i = 2; i <= N; i++) {
		int edgeFrom;
		scanf(" %c%lld%d", &kind[i], &numOfAni[i], &edgeFrom);
		adj[edgeFrom].push_back(i);
	}
	printf("%lld\n", postSearch(1));
	return 0;
}