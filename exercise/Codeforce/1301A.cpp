#include<bits/stdc++.h>
using namespace std;
int T;
string a, b, c;
int main(){
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		a.clear();
		b.clear();
		c.clear();
 
		cin >> a;
		cin >> b;
		cin >> c;
		int N = a.size();
		bool fg = true;
		for (int i = 0; i < N; i++) {
			if (a[i] != c[i] && b[i] != c[i]) {
				fg = false;
				break;
			}
		}
		if (fg) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}