#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pair;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int T; cin >> T; while (T--) {
		// init, clear
		int N, M, ans = 0, mxv = -1e8;
		vector<Pair> arr;
		priority_queue<int> pq;

		cin >> N >> M;
		arr.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i].first;
			pq.push(arr[i].first);
			arr[i].second = i;
		}

		for (int i = 0; ; i++) {
			if (arr[i].first == pq.top()) {
				ans++;
				pq.pop();
				if (arr[i].second == M) {
					cout << ans << "\n";
					break;
				}
			}
			arr.push_back(arr[i]);
		}
	}
	return 0;
}