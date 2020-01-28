#include<iostream>
#include<algorithm>
using namespace std;
int N, K1, K2, max1, max2, T;
int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		max1 = max2 = 0;

		scanf("%d%d%d", &N, &K1, &K2);
		for (int i = 1; i <= K1; i++) {
			int tmp;
			scanf("%d", &tmp);
			max1 = max(max1, tmp);
		}
		for (int i = 1; i <= K2; i++) {
			int tmp;
			scanf("%d", &tmp);
			max2 = max(max2, tmp);
		}
		if (max1 > max2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}