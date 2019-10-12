#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> Pair;
typedef pair<int, Pair> PPair;
const int MAX = 25;

int N, ans = 1;
void print(vector< vector<int> > lis) {
	printf("*****print*****\n\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%4d", lis[i][j]);
		}
		printf("\n");
	}
}

void DFS(int lev, vector<vector<int>> Now) {
	if (lev >= 5) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				ans = max(ans, Now[i][j]);
		//print(Now);
		return;
	}

	vector<vector<int>> Next;

	// �״��---------------------------------------------------------
	Next = Now;

	DFS(lev + 1, Next);

	//printf("�١� level : %d �١�\n", lev);
	//printf("�״�� :: ");
	//print(Next);
	Next.clear();
	//down--------------------------------------------------------------
	Next = Now;

	/*
	for (int j = 1; j <= N; j++) {
		int object = -1; // merge�� object�� ����.
		for (int i = N; i >= 1; i--) {
			if (Next[i][j]) {
				if (object == -1)
					object = i; // merge�� object�� ���� ã�Ҵ�.
				else if (Next[object][j] == Next[i][j]) {
					Next[object][j] += Next[i][j];
					Next[i][j] = 0;
					object = -1;
				}
				else {
					object = -1;
					i++;
				}
			}
		}
	}
	*/
	// down - merge
	for (int j = 1; j <= N; j++) {
		bool IsPushed[MAX] = { 0 };
		for (int i = N; i >= 1; i--) {
			if (Next[i][j] == 0 || IsPushed[i]) continue;
			for (int k = i - 1; k >= 1; k--) {
				if (!Next[k][j] || IsPushed[k] || IsPushed[i]) continue;
				if (Next[i][j] != Next[k][j]) break;
				Next[i][j] += Next[k][j];
				Next[k][j] = 0;
				IsPushed[k] = IsPushed[i] = true;
			}
		}
	}

	// down-mv : 0�� �޲㼭 �����!, 0�� ��� ���� tartget�� ������� �����!
	for (int j = 1; j <= N; j++) {
		for (int i = N; i >= 1; i--) {
			if (Next[i][j]) continue;
			for (int k = i - 1; k >= 1; k--) {
				if (Next[k][j]) {
					Next[i][j] = Next[k][j];
					Next[k][j] = 0;
					break;
				}
			}
		}
	}

	DFS(lev + 1, Next);
	//printf("�١� level : %d �١�\n", lev);
	//print(Now);
	//printf("���� �Ʒ��� �б� :: ");
	//print(Next);
	Next.clear();
	//left-----------------------------------------------------------------
		// merge : object 1���� target 1���, ��ġ��!, target�� 0�̵ȴ�.
	Next = Now;

	/*
	for (int i = 1; i <= N; i++) {
		int object = -1; // merge�� object�� ����.
		for (int j = 1; j <= N; j++) {
			if (Next[i][j]) {
				if (object == -1)
					object = j; // merge�� object�� ���� ã�Ҵ�.
				else if (Next[i][object] == Next[i][j]) {
					Next[i][object] += Next[i][j];
					Next[i][j] = 0;
					object = -1;
				}
				else {
					object = -1;
					j--;
				}
			}
		}
	}
	*/
	// left - merge
	for (int i = 1; i <= N; i++) {
		bool IsPushed[MAX] = { 0 };
		for (int j = 1; j <= N; j++) {
			if (Next[i][j] == 0 || IsPushed[j]) continue;
			for (int k = j + 1; k <= N; k++) {
				if (!Next[i][k] || IsPushed[k] || IsPushed[j]) continue;
				if (Next[i][j] != Next[i][k]) break;
				Next[i][j] += Next[i][k];
				Next[i][k] = 0;
				IsPushed[k] = IsPushed[j] = true;
			}
		}
	}
	// left - mv : 0�� �޲㼭 �����!, 0�� ��� ���� tartget�� ������� �����!
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Next[i][j]) continue;
			for (int k = j + 1; k <= N; k++) {
				if (Next[i][k]) {
					Next[i][j] = Next[i][k];
					Next[i][k] = 0;
					break;
				}
			}
		}
	}

	DFS(lev + 1, Next);
	//printf("�١� level : %d �١�\n", lev);
	//print(Now);
	//printf("���� �������� �б� :: ");
	//print(Next);
	Next.clear();
	//up-----------------------------------------------------------------
	Next = Now;

	/*
	for (int j = 1; j <= N; j++) {
		bool IsPushed[MAX] = {0};
		for (int i = N; i >= 1; i--) {
			if (Next[i][j] == 0 || IsPushed[i]) continue;
			for (int k = i - 1; k >= 1; k--) {
				if (!Next[k][j] || IsPushed[k]) continue;
				if (Next[i][j] != Next[k][j]) break;
				Next[i][j] += Next[k][j];
				Next[k][j] = 0;
				IsPushed[k] = IsPushed[i] = true;
			}
		}
	}
	*/
	// up-merge : 
	for (int j = 1; j <= N; j++) {
		bool IsPushed[MAX] = { 0 };
		for (int i = 1; i <= N; i++) {
			if (Next[i][j] == 0 || IsPushed[i]) continue;
			for (int k = i + 1; k <= N; k++) {
				if (!Next[k][j] || IsPushed[k] || IsPushed[i]) continue;
				if (Next[i][j] != Next[k][j]) break;
				Next[i][j] += Next[k][j];
				Next[k][j] = 0;
				IsPushed[k] = IsPushed[i] = true;
			}
		}
	}

	// up-mv : 0�� �޲㼭 �����!, 0�� ��� ���� tartget�� ������� �����!
	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= N; i++) {
			if (Next[i][j]) continue;
			for (int k = i + 1; k <= N; k++) {
				if (Next[k][j]) {
					Next[i][j] = Next[k][j];
					Next[k][j] = 0;
					break;
				}
			}
		}
	}

	DFS(lev + 1, Next);
	//printf("�١� level : %d �١�\n", lev);
	//print(Now);
	//printf("���� ���� �б� :: ");
	//print(Next);
	Next.clear();
	//right---------------------------------------------------------------
	Next = Now;

	/*
	for (int i = 1; i <= N; i++) {
		bool IsPushed[MAX] = { 0 };
		for (int j = 1; j <= N; j++) {
			if (Next[i][j] == 0 || IsPushed[j]) continue;
			for (int k = j + 1; k <= N; k++) {
				if (!Next[i][k] || IsPushed[k]) continue;
				if (Next[i][j] != Next[i][k]) break;
				Next[i][j] += Next[i][k];
				Next[i][k] = 0;
				IsPushed[k] = IsPushed[j] = true;
			}
		}
	}
	*/
	// right - merge
	for (int i = 1; i <= N; i++) {
		bool IsPushed[MAX] = { 0 };
		for (int j = N; j >= 1; j--) {
			if (Next[i][j] == 0 || IsPushed[j]) continue;
			for (int k = j - 1; k >= 1; k--) {
				if (!Next[i][k] || IsPushed[k] || IsPushed[j]) continue;
				if (Next[i][j] != Next[i][k]) break;
				Next[i][j] += Next[i][k];
				Next[i][k] = 0;
				IsPushed[k] = IsPushed[j] = true;
			}
		}
	}
	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Next[i][j] == 0) continue;
			for (int k = j + 1; k <= N; k++) {
				if (!Next[i][k]) continue;
				if (Next[i][j] != Next[i][k]) break;
				Next[i][j] += Next[i][k];
				Next[i][k] = 0;
			}
		}
	}*/

	// right-mv : 0�� �޲㼭 �����!, 0�� ��� ���� tartget�� ������� �����!
	for (int i = 1; i <= N; i++) {
		for (int j = N; j >= 1; j--) {
			if (Next[i][j]) continue;
			for (int k = j - 1; k >= 1; k--) {
				if (Next[i][k]) {
					Next[i][j] = Next[i][k];
					Next[i][k] = 0;
					break;
				}
			}
		}
	}
	DFS(lev + 1, Next);
	//printf("�١� level : %d �١�\n", lev);
	//print(Now);
	//printf("���� ���������� �б� :: ");
	//print(Next);
	Next.clear();
}
int main() {
	// input
	vector< vector<int> > board;
	scanf("%d", &N);
	board.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		board[i].resize(N + 1);
		for (int j = 1; j <= N; j++)
			scanf("%d", &board[i][j]);
	}
	// algorithm
	DFS(0, board);
	// output
	printf("%d\n", ans);
	return 0;
}