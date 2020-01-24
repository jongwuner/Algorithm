#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 1e9 + 15;
int T, n, s, k, ans;
vector<int> v;
int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		ans = INF;
		v.clear();
		scanf("%d%d%d", &n, &s, &k);
		for (int i = 1, tmp; i <= k; i++) {
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		for (int i = 0; i <= k; i++) {
			for (int op = 0, opt; op <= 1; op++) {
				if (op == 0) opt = 1;
				else opt = -1;
 
				int now = s + (i * opt);
				if (now < 1) continue;
				if (n < now) continue;
 
				bool flag = true;
				for (int j = 0; j < k; j++) {
					if (v[j] == now) {
						flag = false;
						break;
					}
				}
				if (flag)
					ans = min(ans, i);
			}
		}
 
		printf("%d\n", ans);
	}
	return 0;
}