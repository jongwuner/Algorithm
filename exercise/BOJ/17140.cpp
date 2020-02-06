#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> PQ;
const int TIME_MAX = 100, NUM_MAX = 100;
int r, c, k, rl = 3, cl = 3, m[200][200];
bool ans = false;
int main(){
	scanf("%d%d%d", &r, &c, &k);
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			scanf("%d", &m[i][j]);

	for (int T = 0; T <= TIME_MAX; T++) {
		
		if (m[r][c] == k) {
			printf("%d", T);
			ans = true;
			break;
		}
		int tboard[200][200];
		int trl = rl;
		int tcl = cl;

		memset(tboard, 0, sizeof(tboard));
		if (trl >= tcl) {//R
			for (int i = 1; i <= trl; i++) {
				PQ pq;
				vector<int> cnt(NUM_MAX + 1, 0);
				for (int j = 1; j <= tcl; j++) {
					if (m[i][j]) {
						cnt[m[i][j]]++;
					}
				}
				for (int j = 1; j <= NUM_MAX; j++) {
					if (cnt[j])
						pq.push({cnt[j], j});
				}
				int idx = 1;
				while (!pq.empty() && idx <= 100) {
					pii node = pq.top();
					pq.pop();
					tboard[i][idx] = node.second;
					tboard[i][idx + 1] = node.first;
					idx += 2;
				}
				cl = max(cl, idx - 1);
			}
			for (int i = 1; i <= trl; i++)
				for (int j = 1; j <= cl; j++)
					m[i][j] = (tboard[i][j]) ? tboard[i][j] : 0 ;
		}
		else {//C
			for (int j = 1; j <= tcl; j++) {
				PQ pq;
				vector<int> cnt(NUM_MAX + 1, 0);
				for (int i = 1; i <= trl; i++) {
					if (m[i][j]) {
						cnt[m[i][j]]++;
						rl = max(rl, i);
					}
				}
				for (int i = 1; i <= NUM_MAX; i++) {
					if (cnt[i])
						pq.push({ cnt[i], i });
				}
				int idx = 1;
				while (!pq.empty() && idx <= 100) {
					pii node = pq.top();
					pq.pop();
					tboard[idx][j] = node.second;
					tboard[idx + 1][j] = node.first;
					idx += 2;
				}
				rl = max(rl, idx - 1);
			}
			for (int i = 1; i <= rl; i++)
				for (int j = 1; j <= tcl; j++)
					m[i][j] = (tboard[i][j]) ? tboard[i][j] : 0;
		}
	}
	if (!ans)
		printf("-1\n");

	return 0;
}