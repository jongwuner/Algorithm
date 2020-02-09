#include<bits/stdc++.h>
using namespace std;
int T, N, ans;
vector<int> v;
int main(){
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++){
		// clear
		v.clear();
		ans = 0;
 
		// init
		scanf("%d", &N);
		v.resize(2 * N);
		for (int i = 0; i < 2 * N; i++) {
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		printf("%d\n", v[N] - v[N - 1]);
	}
	return 0;
}