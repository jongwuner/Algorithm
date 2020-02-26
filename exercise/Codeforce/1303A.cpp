#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		string S;
		bool fg = false;
		int s = 0;
		int e = 0;
		int ans = 0;
 
		cin >> S;
		
		for (int i = 0; i < S.size(); i++) {
			if (!fg && S[i] == '1') {
				s = i;
				fg = true;
			}
			if (S[i] == '1') {
				e = i;
			}
		}
		for (int i = s; i <= e; i++) {
			if (S[i] == '0')
				ans++;
		}
		if (fg)	printf("%d\n", ans);
		else printf("0\n");
	}
	return 0;
}