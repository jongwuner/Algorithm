#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef pair<int, int> Pair;
 
int N, Q;
vector<bool> V;
map<int, Pair> M;
map<int, bool> numOfWall;
int main() {
	scanf("%d%d", &N, &Q);
	V.resize(N);
	for (int i = 1; i <= Q; i++) {
		int r, c;
		bool ans = true;
		scanf("%d%d", &r, &c);
		if (M.find(c) != M.end()) {
			Pair tp = M[c];
			tp.first ^= (r == 1) ? 1 : 0;
			tp.second ^= (r == 2) ? 1 : 0;
			M[c] = tp;
		}
		else {
			if (r == 1) M[c] = { 1, 0 };
			else if (r == 2) M[c] = { 0, 1 };
		}
		int nowpos = c - 1;
		for (int it = nowpos; it <= nowpos + 1; it++) {
			Pair p[2] = { { 0, 0 }, {0, 0} };
 
			if (M.find(it) != M.end())
				p[0] = M[it];
			if (M.find(it + 1) != M.end())
				p[1] = M[it + 1];
 
			bool flag = true;
			for (int a = 0; a < 2; a++) {
				for (int b = 0; b < 2; b++) {
					if (p[a].first == 1 && p[b].second == 1) {
						flag = false;
						numOfWall[it] = true;
						break;
					}
				}
			}
			if (flag) {
				if (numOfWall.find(it) != numOfWall.end())
					numOfWall.erase(it);
			}
		}
		if (numOfWall.size() != 0) {
			printf("No\n");
		}
		else printf("Yes\n");
	}
	return 0;
}