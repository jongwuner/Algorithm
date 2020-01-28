#include<iostream>
using namespace std;
int n, num, cnt, prime[1001];
int main() {
	for (int i = 2; i <= 1000; i++) prime[i] = i;
	for (int i = 2, check; i * i <= 1000; i++) {
		if (prime[i] == 0) continue;
		for (check = 2 * i; check <= 1000; check += i) prime[check] = 0;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		if (prime[num]) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}