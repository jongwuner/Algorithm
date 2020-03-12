#include<iostream>
#include<vector>
using namespace std;
typedef vector< vector<int> > Vec;
int d, t;
Vec fibo;
Vec mult(Vec a, Vec b) {
	Vec tmp = Vec(d, vector<int>(d, 0));
	for (int i = 0; i < d; i++) 
		for (int j = 0; j < d; j++) 
			for (int k = 0; k < d; k++) 
				tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % 31991;
	return tmp;
}

Vec getAnswer(int t) {
	if (t == 1) return fibo;
	Vec tmp= getAnswer(t / 2);
	tmp = mult(tmp, tmp);
	if (t % 2) tmp = mult(tmp, fibo);
	return tmp;
}

int main() {
	scanf("%d %d", &d, &t);
	fibo = Vec(d, vector<int>(d, 0));
	for (int i = 0; i < d; i++) fibo[0][i] = 1;
	for (int i = 0; i < d - 1; i++) fibo[i + 1][i] = 1;
	Vec ans = getAnswer(t);
	printf("%d\n", ans[0][0]);
	return 0;
}