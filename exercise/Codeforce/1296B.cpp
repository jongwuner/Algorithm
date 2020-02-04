#includebitsstdc++.h
#includevector
#includestring
using namespace std;
typedef long long ll;
 
int T;
 
ll N, ans, tans, state;
int main() {
	scanf(%d, &T);
	for (int tc = 1; tc = T; tc++) {
		clear
		ans = 0;
		
 
		scanf(%lld, &N);
		
		state = N;
		while (state = 10) {
			ans += state  10  10;
			state = (state  10) + (state % 10);
			N = 10;
		}
		printf(%lldn, ans + state);
	}
	return 0;
}