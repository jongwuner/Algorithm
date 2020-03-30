#include<bits/stdc++.h>
using namespace std;
bool visit[42];
int ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

	for (int i = 1; i <= 10; i++) {
		int a;
		cin >> a;
		visit[a % 42] = true;
	}
	for (int i = 0; i < 42; i++) {
		if (visit[i]) ans++;
	}
	cout << ans << "\n";
	return 0;
}