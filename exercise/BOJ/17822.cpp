#include<iostream>
using namespace std;
int N, M, T, cir[55][55], X[55], D[55], K[55], ans, board[55][55];
int main() {
	// input : 
	//		2 <=N(���� ����), M(�Ǹ��� ���� ����), T(ȸ����) <= 50
	//		1<= ���ǿ� ���� �� <= 1000
	//		2<= X(x�� ����� ���ǵ�) <= N
	//		0<= D(d=0�̸� �ð����, d=1�̸� �ݽð�) <= 1
	//			�ð���� ������, �ݽð� ����
	//		1<= K(k�� �̵�) <= M
	scanf("%d%d%d", &N, &M, &T);
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			scanf("%d", &cir[i][j]);


	// algorithm(+input)

	for (int i = 1, X, D, K; i <= T; i++){
		scanf("%d%d%d", &X, &D, &K);
		for (int j = 1; j <= N; j++) {

			//X��� ���Ǹ� �˻�
			if (j % X != 0) continue;


			for (int k = 1; k <= K; k++) { // K�� ȸ��
				if (D == 0) {//�ð���� ȸ��

					int tmp = cir[j][M];
					for (int k = M; k > 1; k--)
						cir[j][k] = cir[j][k - 1];
					cir[j][1] = tmp;

				}
				else if (D == 1) {//�ݽð���� ȸ��

					int tmp = cir[j][1];
					for (int k = 1; k < M; k++)
						cir[j][k] = cir[j][k + 1];
					cir[j][M] = tmp;

				}
			}
		}

		bool flag = false;
		for (int ii = 1; ii <= N; ii++) for (int jj = 1; jj <= M; jj++) board[ii][jj] = cir[ii][jj];

		for (int ii = 1; ii <= N; ii++) {
			//�� �˻�
			for (int jj = 1; jj <= M; jj++) {
				int tmp = board[ii][jj];
				if (tmp == 0) continue;
				bool R = true, L = true, U = true, D = true;
				for (int kk = 1; kk <= M; kk++) {
					if (!R && !L && !U && !D) break;

					int NextR = (jj + kk <= M) ? jj + kk : (jj + kk - 1) % M + 1;
					int NextL = (jj - kk >= 1) ? jj - kk : (M - kk + jj);
					int NextU = ii - kk;
					int NextD = ii + kk;

					if (R && board[ii][NextR] == tmp)
						cir[ii][NextR] = 0, flag = true;
					else
						R = false;

					if (L && board[ii][NextL] == tmp)
						cir[ii][NextL] = 0, flag = true;
					else
						L = false;

					if (U && NextU >= 1 && board[NextU][jj] == tmp)
						cir[NextU][jj] = 0, flag = true;
					else
						U = false;

					if (D && NextD <= N && board[NextD][jj] == tmp)
						cir[NextD][jj] = 0, flag = true;
					else
						D = false;
				}
			}
		}

		if (!flag) {
			double sum = 0, avg, cnt = 0;
			for (int ii = 1; ii <= N; ii++) {
				for (int jj = 1; jj <= M; jj++) {
					if (cir[ii][jj]) {
						cnt++;
						sum += cir[ii][jj];
					}
				}
			}
			avg = (sum / cnt);
			for (int ii = 1; ii <= N; ii++) {
				for (int jj = 1; jj <= M; jj++) {
					if (cir[ii][jj] == 0) continue;
					if (cir[ii][jj] > avg) cir[ii][jj]--;
					else if (cir[ii][jj] < avg) cir[ii][jj]++;
				}
			}
		}
	}
	// output
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			ans += cir[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}