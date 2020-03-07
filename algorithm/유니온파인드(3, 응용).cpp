#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<int> par;
int find(int idx) {
	if (par[idx] < 0) return idx;
	return par[idx] = find(par[idx]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	par[b] += par[a];
	par[a] = b;
	
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0, a, b; i < M; i++) {
		scanf("%d%d", &a, &b);
		merge(a, b);
	}
	par.resize(N);
	for (int i = 0; i < N; i++) par[i] = -1;
}