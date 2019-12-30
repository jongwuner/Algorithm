#include<iostream>
#include<vector>
#define MAX 100005
using namespace std;
int N, cage1Num, cage2Num;
vector<int> hate[MAX];
vector<bool> cage1(MAX, true), cage2(MAX);
int main() {
	scanf("%d", &N);
	for (int i = 1, M; i <= N; i++) {
		scanf("%d", &M);
		for (int j = 0, t; j < M; j++) {
			scanf("%d", &t);
			hate[i].push_back(t);
		}
	}

	cage1Num = N;
	while (true) {
		int flag = true;
		for (int i = 1; i <= N; i++) {
			if (cage1[i]) {
				int cnt = 0;;
				for (int j = 0; j < hate[i].size(); j++) {
					if (cage1[hate[i][j]]) {
						cnt++;
					}
				}
				if (cnt > 1) {
					cage1[i] = false;
					cage2[i] = true;
					cage1Num--;
					cage2Num++;
					flag = false;
				}
			}
		}
		if (flag) break;

		flag = true;
		for (int i = 1; i <= N; i++) {
			if (cage2[i]) {
				int cnt = 0;
				for (int j = 0; j < hate[i].size(); j++) {
					if (cage2[hate[i][j]]) {
						cnt++;
					}
				}
				if (cnt > 1) {
					cage2[i] = false;
					cage1[i] = true;
					cage2Num--;
					cage1Num++;
					flag = false;
				}
			}
		}

		if (flag) break;
	}
	printf("%d", cage1Num);
	for (int i = 1; i <= N; i++) {
		if(cage1[i]) printf(" %d", i);
	}
	printf("\n%d", cage2Num);
	for (int i = 1; i <= N; i++) {
		if (cage2[i]) printf(" %d", i);
	}
	return 0;
}