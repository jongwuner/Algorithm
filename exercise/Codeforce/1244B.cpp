#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int testCases;
	scanf("%d", &testCases);
	while (testCases--) {
		int N, ans; string s;
		scanf("%d", &N);
		cin >> s;
		ans = N;
		for (int i = 0; i < N; i++) {
			if (s[i] == '1') {
				ans = max(ans, 2 * max(i + 1, N - i));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}