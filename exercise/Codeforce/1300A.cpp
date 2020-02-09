#include<bits/stdc++.h>
using namespace std;
int T, N, ans, sum;
vector<int> v;
int main(){
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		//clear
		v.clear();
		ans = 0;
		sum = 0;
 
		scanf("%d", &N);
		v.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &v[i]);
			if (v[i] == 0) ans++;
			sum += v[i];
		}
		if (sum + ans == 0) ans++;
		printf("%d\n", ans);
	}
	return 0;
}