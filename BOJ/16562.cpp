#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int main() {
	int N, M;
	scanf("%d%d", &, &M);
	v.resize(N + 1, -1);
	for (int i = 1, g; i <= M; i++) {
		scanf("%d", &g);
		while (g) {
			merge(i, g); // µµÅ·


			g--;
		}
	}
	return 0;
}