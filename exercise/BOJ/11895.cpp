#include<iostream>
#include<algorithm>
using namespace std;
int N, arr[1005], minval = 1e9, xorSum, sum;
int main() {
	scanf("%d", &N);
	for (int i = 1, t; i <= N; i++) {
		scanf("%d", &t);
		sum += t;
		xorSum ^= t;
		minval = min(minval, t);
	}
	if (!xorSum) printf("%d\n", sum - minval);
	else printf("0\n");
	return 0;
}