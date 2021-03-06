#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#define INF 1000000000
using namespace std;

int N, res = INF, a[25][25];
bool chk[25];
void goAnswer(int lev, int num) {
	if (lev > N / 2) {
		int sum = 0;
		int psum = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (chk[i] && chk[j]) {
					sum += a[i][j] + a[j][i];
				}
				else if (!chk[i] && !chk[j]) {
					psum += a[i][j] + a[j][i];
				}
			}
		}
		res = min(res, abs(sum - psum));
		return;
	}
	chk[num] = true;
	for (int i = num + 1; i <= N; i++) {
		goAnswer(lev + 1, i);
	}
	chk[num] = false;
}
int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	goAnswer(0, 0);
	printf("%d\n", res);
	return 0;
}