#include<iostream>
#include<string>
using namespace std;
int N;
int cnt[2];
string s;
int main() {
	scanf("%d", &N);
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'L') cnt[0]++;
		else if (s[i] == 'R') cnt[1]++;
	}
	printf("%d\n", cnt[0] + cnt[1] + 1);
	return 0;
}