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
		for (int i = 1 << N; i >= 1; i = i >> 1) { // 간격
			for (int j = 0; 1 + j*i <= 1 << N; j++) { // 시작점
				bool flag = true;
				for (int k = 1 + j * i; k < 1 + (j + 1) * i; k++) { // 작은 루프
					if (nogame[k] == false) { // 이 루프에서 하나라도 게임을 할 경우 더 볼필요도 없다!. 더 작은 단위는 계속 쪼개어 볼테니!
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
					for (int k = 1 + j * i; k < 1 + (j + 1) * i; k++) { // 작은 루프
						nogame[k] = false; // 체크했으니 
					}
				}
			}
			if (cont) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}