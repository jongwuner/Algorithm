#include <iostream>
#include <queue>
#define MAX 25
#define INFINITY 100

using namespace std;

int score[MAX][2];
int play[MAX][MAX];
bool bfs(int **graph, int size, int *path, int s, int t) {
	queue <int> Q;
	bool *isVisited = new bool[size];

	for (int i = 0; i < size; i++) {
		isVisited[i] = false;
	}

	isVisited[s] = true;
	Q.push(s);

	path[s] = -1;

	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();

		for (int j = 0; j < size; j++) {
			if (!isVisited[j] && graph[i][j] > 0) {
				isVisited[j] = true;
				Q.push(j);
				path[j] = i;
			}
		}
	}
	return isVisited[t];
}


int fordFulkerson(int **graph, int size, int s, int t) {
	int **residualGraph = new int*[size];
	int *path = new int[size];
	int maxFlow = 0;

	// Initialize Rsidual Graph
	for (int i = 0; i < size; i++) {
		residualGraph[i] = new int[size];

		for (int j = 0; j < size; j++) {
			residualGraph[i][j] = graph[i][j];
		}
	}

	// Find Augmenting Path
	while (true) {
		bool isContinued = bfs(residualGraph, size, path, s, t);
		if (!isContinued) break;

		int pathFlow = INFINITY;

		for (int j = t; j != s; j = path[j]) {
			int i = path[j];

			if (pathFlow > residualGraph[i][j]) {
				pathFlow = residualGraph[i][j];
			}
		}

		for (int j = t; j != s; j = path[j]) {
			int i = path[j];
			residualGraph[i][j] -= pathFlow;
			residualGraph[j][i] += pathFlow;
		}
		maxFlow += pathFlow;
	}
	return maxFlow;
}


bool kLeague(int team, int n) {
	int **newScore = NULL;
	int **graph = NULL;
	int index = 0; // index of play
	int size = 0; // size of graph
	int sumLose = 0;
	int maxFlow = 0;
	bool result = true;

	/* Score */
	// Copy Score
	newScore = new int*[n];

	for (int i = 0; i < n; i++) {
		newScore[i] = new int[2];
		newScore[i][0] = score[i][0];
		newScore[i][1] = score[i][1];
	}

	// New Score
	for (int i = 0; i < n; i++) {
		if (i != team) {
			newScore[team][0] += play[team][i]; // 현재 팀의 승 증가
			newScore[i][1] += play[team][i]; // 상대 팀의 패 증가
		}
	}

	// Check Score
	for (int i = 0; i < n; i++) {
		if (newScore[team][0] - newScore[i][0] < 0) {
			result = false;
			break;
		}
	}

	if (result) {
		/* Graph */
		// Count Vertax
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((i != team && j != team) && play[i][j] > 0) {
					size++;
				}
			}
		}

		index = 1 + n;
		size = 1 + n + size + 1; // 그래프 정점 수 : s + (상태 team 수) + (경기 수) + t
		graph = new int*[size];

		for (int i = 0; i < size; i++) {
			graph[i] = new int[size];
			for (int j = 0; j < size; j++) {
				graph[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			if (i != team) {
				graph[0][i + 1] = newScore[team][0] - newScore[i][0];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int game = play[i][j];
				if ((i != team && j != team) && game > 0) {
					// team -> play
					graph[i + 1][index] = INFINITY;
					graph[j + 1][index] = INFINITY;

					// paly -> t
					graph[index++][size - 1] = game;
					sumLose += game;
				}
			}
		}
		maxFlow = fordFulkerson(graph, size, 0, size - 1);
		result = (sumLose == maxFlow);
	}

	return result;
}

int main() {
	int testCases;

	scanf("%d", &testCases);
	while (testCases--) {
		int n;// team
		bool result[MAX]; // win : true
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &score[i][0], &score[i][1]);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &play[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			result[i] = kLeague(i, n);
		}
		for (int i = 0; i < n; i++) {
			if (result[i]) {
				printf("%d ", i + 1);
			}
		}
		printf("\n");
	}
	return 0;
}
