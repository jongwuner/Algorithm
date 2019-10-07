#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int N;
vector<int> p;
vector<ll> w;
int find(int idx) {
	if (p[idx] < 0) return idx;
	int tidx = find(p[idx]);
	w[idx] += w[p[idx]];
	p[idx] = tidx;
	return tidx;
}
void merge(int a, int b) {
	a = find(a);
	if (a == b) return;
	p[a] = b;
	w[a] = (abs(b - a)) % 1000;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		p.clear();
		w.clear();
		scanf("%d", &N);
		p.resize(N + 1, -1);
		w.resize(N + 1, 0);
		for (;;) {
			char type;
			scanf(" %c", &type);
			if (type == 'E') {
				int a;
				scanf("%d", &a);
				find(a);
				printf("%lld\n", w[a]);
			}
			else if (type == 'I') {
				int a, b;
				scanf("%d %d", &a, &b);
				merge(a, b);
			}
			else if (type == 'O')
				break;
		}
	}
	return 0;
}