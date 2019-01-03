#include<iostream>
#include<stack>
using namespace std;
int main() {
	int N;
	
	while (1) {
		bool flag = false;

		scanf("%d", &N);
		if (!N) return 0;
		while(!flag) {
			stack<int> S;
			int order = 0;

			for (int i = 0, target; i < N; i++) {
				
				scanf("%d", &target);
				if (target == 0) {
					flag = true;
					break;
				}

				while (order < N && order != target) {
					if (S.size() > 0 && S.top() == target) break;
					S.push(++order);
				}
				if (target == S.top()) S.pop();
			}
			if (!flag && S.size() == 0)
				printf("Yes\n");
			else if (!flag)
				printf("No\n");

			if (flag) {
				printf("\n");
			}
		}
	}

	return 0;
}