#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, M, a[105], mv=-1e8;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				int sum = a[i] + a[j] + a[k];
				if (sum <= M && sum > mv) {
					mv = sum;
				}
			}
		}
	}
	cout << mv << "\n";
	return 0;
}