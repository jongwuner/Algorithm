#include<bits/stdc++.h>
#define MAX 10
#define TOKEN 4
using namespace std;

int arr[15], pos[5], visit[4][45];
bool completed[4];
int ans = -1e9;
int conv[35];
void init() {
	for (int i = 1; i <= 20; i++)
		conv[i] = 2 * i;
	conv[21] = 0;
	conv[22] = 13;
	conv[23] = 16;
	conv[24] = 19;
	for (int i = 25; i <= 28; i++)
		conv[i] = i;
	conv[29] = 22;
	conv[30] = 24;
	conv[31] = 30;
	conv[32] = 35;
}

void getAnswer(int lev, int tot) {
	if (lev > MAX) {
		ans = max(ans, tot);
		return;
	}

	// a[lev]만큼 이동 -> 이동 후 적혀있는 칸에 점수만큼 더해주기.
	for (int i = 1; i <= TOKEN; i++) {
		if (pos[i] == 21) continue;
		int tmpPos = pos[i];
		int nextNode = -1;

		if (pos[i] == 5 || (22 <= pos[i] && pos[i] <= 24)) {
			int nextR = pos[i] + arr[lev];
			if (pos[i] == 5) {
				if (nextR == 6) nextNode = 22;
				else if (nextR == 7) nextNode = 23;
				else if (nextR == 8) nextNode = 24;
				else if (nextR == 9) nextNode = 25;
				else if (nextR == 10) nextNode = 31;
			}
			else {
				if (22 <= nextR && nextR <= 25) nextNode = nextR;
				else if (nextR == 26) nextNode = 31;
				else if (nextR == 27) nextNode = 32;
				else if (nextR == 28) nextNode = 20;
				else if (nextR >= 29) {
					nextNode = 21;
					completed[i] = true;
				}
			}
		}
		else if (pos[i] == 10 || (29 <= pos[i] && pos[i] <= 30)) {
			int nextU = pos[i] + arr[lev];
			if (pos[i] == 10) {
				if (nextU == 11) nextNode = 29;
				else if (nextU == 12) nextNode = 30;
				else if (nextU == 13) nextNode = 25;
				else if (nextU == 14) nextNode = 31;
				else if (nextU == 15) nextNode = 32;
			}
			else {
				if (29 <= nextU && nextU <= 30) nextNode = nextU;
				else if (nextU == 31) nextNode = 25;
				else if (nextU == 32) nextNode = 31;
				else if (nextU == 33) nextNode = 32;
				else if (nextU == 34) nextNode = 20;
				else if (nextU >= 35) {
					nextNode = 21;
					completed[i] = true;
				}
			}
		}
		else if (pos[i] == 15 || (26 <= pos[i] && pos[i] <= 28)) {
			int nextL = pos[i] - arr[lev];
			if (pos[i] == 15) {
				if (nextL == 14) nextNode = 28;
				else if (nextL == 13) nextNode = 27;
				else if (nextL == 12) nextNode = 26;
				else if (nextL == 11) nextNode = 25;
				else if (nextL == 10) nextNode = 31;
			}
			else {
				if (25 <= nextL && nextL <= 28) nextNode = nextL;
				else if (nextL == 24) nextNode = 31;
				else if (nextL == 23) nextNode = 32;
				else if (nextL == 22) nextNode = 20;
				else if (nextL <= 21) {
					nextNode = 21;
					completed[i] = true;
				}
			}
		}
		else if (pos[i] == 25 || (31 <= pos[i] && pos[i] <= 32)) {
			int nextUU = pos[i] + arr[lev];
			if (pos[i] == 25) {
				if (nextUU == 26) nextNode = 31;
				else if (nextUU == 27) nextNode = 32;
				else if (nextUU == 28) nextNode = 20;
				else if (nextUU >= 29) {
					nextNode = 21;
					completed[i] = true;
				}
			}
			else {
				if (31 <= nextUU && nextUU <= 32) nextNode = nextUU;
				else if (nextUU == 33) nextNode = 20;
				else if (nextUU >= 34) {
					nextNode = 21;
					completed[i] = true;
				}
			}
		}
		else {
			nextNode = pos[i] + arr[lev];
			if (nextNode >= 21) {
				nextNode = 21;
				completed[i] = true;
			}
		}

		for (int k = 1; k <= 4; k++) {
			if (k == i) continue;
			if (nextNode != 21 && pos[k] == nextNode) {
				nextNode = -1;
				break;
			}
		}

		if (nextNode != -1) {
			pos[i] = nextNode;
			getAnswer(lev + 1, tot + conv[nextNode]);
			pos[i] = tmpPos;
		}
		
	}
}
int main() {
	init();
	// input
	for (int i = 1; i <= MAX; i++)
		scanf("%d", &arr[i]);

	// algorithm
	for (int i = 1; i <= TOKEN; i++) {
		getAnswer(1, 0);
	}

	// output
	printf("%d\n", ans);
	return 0;
}