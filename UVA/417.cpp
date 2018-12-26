#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
char tmp[10];
bool visit[10], flag = false;
int cnt, answer;
vector<char> list, ans;
void init() {
	list.clear(); ans.clear();
	flag = false;
	cnt = answer = 0;
	for (int i = 0; i < 10; i++) {
		tmp[i] = NULL;
		visit[i] = false;
	}
}
void getAnswer(int lev, int a) {
	if (lev == 5) {
		if (a == 0) return;
		++cnt;
		if (list == ans) {
			flag = true;
			answer = cnt;
		}
		return;
	}
	if (a == 0) {
		getAnswer(lev + 1, 0);
	}
	for (int i = a + 1; i <= 26; i++) {
		list.push_back('a' + i - 1);
		getAnswer(lev + 1, i);
		list.pop_back();
	}
	if (flag) return;
}
int main() {
	while (scanf("%s", tmp) == 1) {
		for (int i = 0; tmp[i]; i++) {
			ans.push_back(tmp[i]);
		}
		getAnswer(0, 0);
		printf("%d\n", answer);
		init();
	}
	return 0;
}