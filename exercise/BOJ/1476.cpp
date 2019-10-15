#include<iostream>
using namespace std;
int main() {
	int i = 0;
	int A, B, C, a = 0, b = 0, c = 0;
	scanf("%d%d%d", &A, &B, &C);
	while (a != A || b != B || c != C) {
		i++;
		a = (i % 15 == 0) ? 15 : i % 15;
		b = (i % 28 == 0) ? 28 : i % 28;
		c = (i % 19 == 0) ? 19 : i % 19;
	}
	printf("%d\n", i);
	return 0;
}