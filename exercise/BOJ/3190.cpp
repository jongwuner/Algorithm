#include<iostream>
#include<vector>
using namespace std;

typedef pair<int, int> Pair;
typedef pair<int, char> cPair;
const int mvY[] = { 0, 1, 0, -1 }; // 0, 1, 2, 3 == %4
const int mvX[] = { 1, 0, -1, 0 };

int main() {
	// input
	int N, K, L, mod = 0, mvPtr = 1, ans = 0, currTime = 0, len = 1;
	bool apple[105][105] = { 0 };
	vector< vector<int> > tboard;

	Pair currPos = {1, 1};
	cPair mv[105];


	scanf("%d%d", &N, &K);
	for (int i = 1, y, x; i <= K; i++) {
		scanf("%d%d", &y, &x);
		apple[y][x] = true;
	}

	scanf("%d", &L);
	for (int i = 1, sec; i <= L; i++) 
		scanf("%d %c", &mv[i].first, &mv[i].second);
	
	tboard.resize(N + 2);
	for (int i = 0; i <= N + 1; i++)
		tboard[i].resize(N + 2, -1);

	// algorithm
	tboard[1][1] = 0;

	while (1) {
		//다음에 나아가야할 방향.좌표
		if (mv[mvPtr].first == currTime) {
			if (mv[mvPtr].second == 'D') mod = (mod + 1) % 4;
			else if (mv[mvPtr].second == 'L') mod = (mod - 1 == -1) ? 3 : (mod - 1);
			mvPtr++;
		}
		// 바깥으로 나갈때
		int nextY = currPos.first + mvY[mod];
		int nextX = currPos.second + mvX[mod];

		if (nextY < 1 || nextY > N || nextX < 1 || nextX > N) {
			ans = currTime + 1;
			break;
		}
		// 자기자신을 물때
		else if (tboard[nextY][nextX] != -1 && currTime + 1 - len <= tboard[nextY][nextX]) {
			ans = currTime + 1;
			break;
		}
		else if(apple[nextY][nextX]){
			//사과를 먹을때
			apple[nextY][nextX] = false;
			len++;
		}

		tboard[nextY][nextX] = ++currTime;
		currPos = { nextY, nextX };
	
	}

	// output
	printf("%d\n", ans);
	return 0;
}