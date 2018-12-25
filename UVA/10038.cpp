#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool flag;
int N, a[3005], b[3005];
int main() {
	while (scanf("%d", &N) == 1) {
		flag = true;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i < N; i++) {
			b[i] = abs(a[i + 1] - a[i]);
		}
		sort(b + 1, b + N);
		for (int i = 1; i < N; i++) {
			if (b[i] != i) {
				flag = false;
				break;
			}
		}
		if (flag) printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}