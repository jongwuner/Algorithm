
#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
int T, N;
vector<int> v;
string S;
int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		// clear
		v.clear();
		S.clear();
		int oddFg = 0, evenFg = 0;
		// init
		scanf("%d", &N);
		v.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &v[i]);
		}
 
		for (int i = 1; i <= N; i++) {
			if (v[i] % 2 == 1) oddFg++;
			if (v[i] % 2 == 0) evenFg++;
		}
		if (oddFg && evenFg)
			S = "YES";
		else if (evenFg == 0 && oddFg % 2 == 0)
			S = "NO";
		else if (oddFg == 0)
			S = "NO";
		else
			S = "YES";
		cout << S << "\n";
	}
	return 0;
}