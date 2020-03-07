#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 100005;
int dist[105][105];
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = INF;

	for (int i = 1, a, b, c; i <= M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if(dist[i][k] != INF && dist[k][j] != INF)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%d ", (dist[i][j] >= INF) ? 0 : dist[i][j]);
		printf("\n");
	}
	return 0;
}


6 6

1 2 3
1 3 10
3 5 2
2 5 5
2 4 7
5 6 -10

