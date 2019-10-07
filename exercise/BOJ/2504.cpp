#include<iostream>
using namespace std;
int N, M, A[10005];
int sum(int idx) {
	int ans = 0;
	while (idx > 0) {
		ans += tree[idx];
		idx -= (idx & -idx);
	}
}
void update(int idx) {

}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		L[i] = (i & -i);
	}
	

	return 0;
}