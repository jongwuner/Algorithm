#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string S;
vector<pair<string, int>> vs;
int N;
int main() {
	int T; cin >> T; while (T--) {
		vs.clear();
		S.clear();
 
 
		cin >> N >> S;
		for (int i = 0; i < N; i++) { // i + 1== k
			string ts;
			string subS1 = S.substr(i, N - i);
			string subS2;
			ts += subS1;
			for (int j = 0; j < i; j++)
				subS2 += S[j];
			if ((N - i) % 2 == 1)
				reverse(subS2.begin(), subS2.end());
			ts += subS2;
			vs.push_back({ ts, i + 1 });
		}
		sort(vs.begin(), vs.end());
		cout << vs[0].first << "\n" << vs[0].second << "\n";
	}
	return 0;
}