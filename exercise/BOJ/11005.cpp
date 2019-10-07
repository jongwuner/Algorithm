#include<iostream>
#include<stack>
#include<cstring>
#include<cmath>
using namespace std;
char ans[10000];
int b, len, s;
stack<char> ss;
void toB(int s, int B) {
	while (s > 0) {
		if (s % B >= 10) ss.push(s % B - 10 + 'A');
		else ss.push(s % B + '0');
		s /= B;
	}
}
int main() {
	scanf("%d %d", &s, &b);
	toB(s, b);
	while (!ss.empty()) {
		printf("%c", ss.top());
		ss.pop();
	}
	return 0;
}