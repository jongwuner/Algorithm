#include<iostream>
#include<queue>
#include<functional>
#define MAX 5000005
using namespace std;
typedef pair<int, int> Pair;
int arr[MAX];
int main() {
	int N, L;
	priority_queue<Pair, vector<Pair>, greater<Pair>> PQ;
	scanf("%d%d", &N, &L);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		PQ.push({ arr[i], i });
		int idx = PQ.top().second;
		int val = PQ.top().first;
		while (idx <= i - L) {
			PQ.pop();
			val = PQ.top().first;
			idx = PQ.top().second;
		}
		printf("%d ", val);
	}
	return 0;
}