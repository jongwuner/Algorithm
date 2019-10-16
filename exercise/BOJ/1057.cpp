#include<iostream>
#include<cmath>
using namespace std;
int N, k;
int getAnswer(int i, int t, int s, int b) {
	if (s <= (t >> 1) && b <= (t >> 1)) {
		return getAnswer(i - 1, t >> 1, s, b);
	}
	else if (s <= (t >> 1) && (t >> 1) < b && b <= t) {
		return i;
	}
	else if ((t >> 1) < s && s <= t && (t >> 1) < b && b <= t) {
		return getAnswer(i - 1, t >> 1, s - (t>>1), b - (t>>1));
	}
}
int main() {
	int A, B, bn, sn, size = 1, cnt = 0;
	scanf("%d%d%d", &N, &A, &B);
	bn = (A > B) ? A : B;
	sn = (A <= B) ? A : B;
	while (size < N) {
		cnt++;
		size = size << 1;
	}
	k = size;

	printf("%d\n", getAnswer(cnt, k, sn, bn));
	return 0;
}