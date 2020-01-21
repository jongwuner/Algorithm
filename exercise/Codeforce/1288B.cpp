#include<iostream>
using namespace std;
typedef long long ll;
int testCases;
ll nine[10] = {0, 9,};
int main() {
	for (int i = 2; i <= 9; i++) {
		nine[i] = nine[i - 1] * 10 + 9;
	}
 
	scanf("%d", &testCases);
	for (int tc = 1; tc <= testCases; tc++) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		ll numa = a;
		ll numb = b;
		ll cnta = 0;
		ll cntb = 0;
 
		for (int i = 9; i >= 1; i--) {
			if (numa - nine[i] >= 0) {
				cnta = i;
				break;
			}
		}
 
		for (int i = 9; i >= 1; i--) {
			if (numb - nine[i] >= 0) {
				cntb = i;
				break;
			}
		}
 
		printf("%lld\n", a * cntb);
	}
	return 0;
}