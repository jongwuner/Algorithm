#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, N, M, ptr;
vector<int> vi;
vector<int> cnt;
string S;
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// clear
		vi.clear();
		cnt.clear();
		S.clear();
		ptr = 0;
		// init
		cin >> N >> M >> S;
		vi.resize(M + 1);
		cnt.resize(30);
		for (int i = 0; i < M; i++)
			cin >> vi[i];
		sort(vi.begin(), vi.end());
 
		
		for (int i = 0; i < N; i++) {
			while (ptr <= M && i + 1 > vi[ptr]) ptr++;
			cnt[S[i] - 'a'] += (M + 1 - ptr + 1);
		}
		for (int i = 0; i < 26; i++)
			cout << cnt[i] << " ";
		cout << "\n";
	}
	return 0;
}