#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define PLUS 1
#define MINUS 2
#define MULT 3
#define DIV 4
using namespace std;
int N, A[15], tmp[5], cal[15], maxVal = -1e9, minVal = 1e9;
vector<int> lis;
bool visit[15];
void goAnswer(int lev) {
	if (lev == N - 1) {
		int total = A[1];
		for (int i = 0; i < lis.size(); i++) {
			if (cal[lis[i]] == PLUS)
				total += A[i + 2];
			else if (cal[lis[i]] == MINUS)
				total -= A[i + 2];
			else if (cal[lis[i]] == MULT)
				total *= A[i + 2];
			else if (cal[lis[i]] == DIV)
				total /= A[i + 2];
		}
		maxVal = max(maxVal, total);
		minVal = min(minVal, total);
		return;
	}
	for (int i = 1; i <= N - 1; i++) {
		if (visit[i]) continue;

		visit[i] = true;
		lis.push_back(i);
		goAnswer(lev + 1);
		lis.pop_back();
		visit[i] = false;
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);
	for (int i = 1; i <= 4; i++)
		scanf("%d", &tmp[i]);
	
	int sum = 0;
	for (int i = 1; i <= 4; i++) {
		for (int j = sum + 1; j <= sum + tmp[i]; j++) {
			cal[j] = i;
		}
		sum += tmp[i];
	}

	goAnswer(0);
	printf("%d\n%d\n", maxVal, minVal);
	return 0;
}