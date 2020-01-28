#include<iostream>
#include<vector>
using namespace std;
int T, N;
vector<int> v;
int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		v.clear();
		bool flag = false;
 
		scanf("%d", &N);
		v.resize(N + 1);
 
		for (int i = 1; i <= N; i++)
			scanf("%d", &v[i]);
 
		for (int i = 2; i <= N; i++) {
			if (abs(v[i] - v[i - 1]) >= 2) {
				printf("YES\n%d %d\n", i - 1, i);
				flag = true;
				break;
			}
		}
		if (flag == false) {
			printf("NO\n");
		}
	}
	return 0;
}