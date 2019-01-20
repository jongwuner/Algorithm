#include<cstdio>
#define MAX 35
using namespace std;
char S[MAX];
bool visit[MAX];
bool flag = true;
int search(int idx) {
	int ans = 0;
	bool closed = false;

	visit[idx] = true;
	for (int i = idx + 1; S[i] && flag; i++) {
		if (visit[i]) continue;
		if (S[i] == '(') 
			ans += (search(i) * 2);
		
		else if (S[i] == '[') 
			ans += (search(i) * 3);
		
		else if (S[i] == ')') {
			visit[i] = true;
			if (!idx || S[idx] == '[') {
				flag = false;
				return 0;
			}
			else if (S[idx] == '(') {
				closed = true;
				return ans ? ans : 1;
			}
		}
		else if (S[i] == ']') {
			visit[i] = true;
			if (!idx || S[idx] == '(') {
				flag = false;
				return 0;
			}
			else if (S[idx] == '[') {
				closed = true;
				return ans ? ans : 1;
			}
		}
	}
	if (idx && !closed)
		flag = false;
	
	return ans;
}
int main() {
	scanf(" %s", S + 1);
	int Ans = search(0);
	printf("%d\n", (flag) ? Ans : flag);
	return 0;
}