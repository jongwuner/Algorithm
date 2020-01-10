#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int N, K;
long long ans;
vector<string> S;
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int i = 0; i < K; i++) {
			if (s[i] == 'S') s[i] = '0';
			else if (s[i] == 'E') s[i] = '1';
			else if (s[i] == 'T') s[i] = '2';
		}
		S.push_back(s);
	}
	sort(S.begin(), S.end());
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			string ts;
			for (int idx = 0; idx < K; idx++) {
				if (S[i][idx] == S[j][idx])
					ts.push_back(S[i][idx]);
				else {
					for (int tmp = 0; tmp <= 2; tmp++) {
						char m = tmp + '0';
						if (m == S[i][idx]) continue;
						if (m == S[j][idx]) continue;
						ts.push_back(m);
						break;
					}
				}
			}
			int find = lower_bound(S.begin(), S.end(), ts) - S.begin();
			if (j < find && find < N && S[find] == ts) 
				ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}