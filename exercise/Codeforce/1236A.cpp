#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int testCases;
	scanf("%d", &testCases);
	while (testCases--) {
		int a, b, c, ans = 0;
		scanf("%d%d%d", &a, &b, &c);
		for (int x = 0; x <= 50; x++) {
			for (int y = 0; y <= 50; y++) {
				if (a - x < 0 || b - 2 * x - y < 0 || c - 2 * y < 0)
					continue;
				ans = max(ans, x + y);
			}
		}
		printf("%d\n", ans * 3);
	}
	return 0;
}