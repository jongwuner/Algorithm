#include<iostream>
#define MAX 1000
using namespace std;
int dp[MAX + 5];
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	for (int i = 1; i <= MAX; i++) {
		int tmp = 0;
		for (int j = 1; j <= i - 1; j++) {
			if (gcd(i, j) == 1) {
				tmp++;
			}
		}
		dp[i] = dp[i - 1] + tmp;
	}
	while (testCases--) {
		int N;
		scanf_s("%d", &N);
		printf("%d\n", 2 * dp[N] + 3);
	}
	return 0;
}