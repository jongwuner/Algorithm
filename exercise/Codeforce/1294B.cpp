
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> Pair;
int N;
bool flag;
vector<Pair> p;
vector<char> ans;
int main() {
	int testCases;
	scanf("%d", &testCases);
	for (int tc = 1; tc <= testCases; tc++) {
		p.clear();
		ans.clear();
		flag = true;
 
		scanf("%d", &N);
		p.resize(N);
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &p[i].first, &p[i].second);
		}
		sort(p.begin(), p.end());
		Pair pos = {0, 0};
		for (int i = 0; i < N; i++) {
			int w;
			int h;
			w = p[i].first - pos.first;
			h = p[i].second - pos.second;
			if (w < 0 || h < 0) {
				printf("NO\n");
				flag = false;
				break;
			}
			for (int k = 0; k < w; k++) {
				ans.push_back('R');
			}
			for (int k = 0; k < h; k++) {
				ans.push_back('U');
			}
			pos = p[i];
		}
		if (flag) {
			printf("YES\n");
			for (int k = 0; k < ans.size(); k++)
				printf("%c", ans[k]);
			printf("\n");
		}
	}
	return 0;
}