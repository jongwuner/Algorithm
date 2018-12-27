#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		bool cont = false;
		int N, M, ans = 0;
		bool nogame[1050];

		memset(nogame, false, sizeof(nogame));
		scanf("%d %d", &N, &M);
		for (int i = 1, tmp; i <= M; i++) {
			scanf("%d", &tmp);
			nogame[tmp] = true;
		}
		for (int i = 1 << N; i >= 1; i = i >> 1) { 
			for (int j = 0; 1 + j*i <= 1 << N; j++) { 
				bool flag = true;
				for (int k = 1 + j * i; k < 1 + (j + 1) * i; k++) { 
					if (nogame[k] == false) { 
						flag = false;
						break;
					}
				}
				if (flag && i == 1 << N) {
					ans = 0;
					cont = true;
					break;
				}
				else if(flag){
					ans++;
					for (int k = 1 + j * i; k < 1 + (j + 1) * i; k++) { 
						nogame[k] = false; 
					}
				}
			}
			if (cont) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}