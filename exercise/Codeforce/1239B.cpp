#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int N;
ll arr[100005], bn, sn, bb, ss;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + N);
	if (N % 2 == 1) {//È¦¼ö
		for (int i = N - 1; i >= (N - 1) / 2; i--) {
			bb += arr[i];
		}
		for (int i = 0; i < (N - 1) / 2; i++) {
			ss += arr[i];
		}
	}
	else {//Â¦¼ö
		for (int i = N - 1; i >= N / 2; i--) {
			bb += arr[i];
		}
		for (int i = 0; i < N / 2; i++) {
			ss += arr[i];
		}
	}
	bn = bb * bb;
	sn = ss * ss;
	printf("%lld\n", bn + sn);
	return 0;
}