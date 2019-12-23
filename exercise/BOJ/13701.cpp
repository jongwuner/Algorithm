#include<iostream>
#define BIT 32
using namespace std;
int N, visit[(1 << 25) / BIT];
int main() {
	while (scanf("%d", &N) != EOF) {
		int a = N / BIT;
		int b = 1 << (N % BIT);
		if (visit[a] & b) continue;
		printf("%d ", N);
		visit[a] += b;
	}
	return 0;
}