#include<iostream>
#include<vector>
using namespace std;
vector< vector<char> > arr;
vector<int> mount;
int main() {
	int N, M, X;
	scanf("%d%d%d", &N,&M,&X);
	arr.resize(N + 1);
	mount.resize(M + 1);
	for (int i = 0; i < N + 1; i++)
		arr[i].resize(M + 1, '.');

	for (int i = 1; i <= M; i++) 
		scanf("%d", &mount[i]);
	
	for (int j = 1; j <= M; j++) {
		for (int i = 1; i <= N; i++) {
			if (N + 1 - i <= mount[j]) 
				arr[i][j] = '#';
			else if (N + 1 - i < X) {
				if (j % 3 == 0)
					arr[i][j] = '|';
			}
			else arr[i][j] = '.';

			if (N + 1 - i == X) {
				if (arr[i][j] == '#')
					arr[i][j] = '*';
				else 
					arr[i][j] = '-';
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) 
			printf("%c", arr[i][j]);
		printf("\n");
	}
	return 0;
}