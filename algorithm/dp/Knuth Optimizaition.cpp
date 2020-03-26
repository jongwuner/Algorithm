#define MAX 1<<30
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
using namespace std;
 
int novel[500];
int p_sum[500];
int dp[500][500];
int A[500][500];
int main(void) {
    int T, m,  i, j, k; 
    scanf("%d", &T);
    for (m = 0; m < T; m++) {
        int K;
        scanf("%d", &K);
        for (i = 0; i < K; i++) {
            scanf("%d", &novel[i]);
            if (i == 0) p_sum[i] = novel[i];
            else p_sum[i] = p_sum[i - 1] + novel[i];        //첫번째부터 i번째까지 파일크기 합
        }
        for (i = 0; i < K; i++) {    //cost 배열 초기화
            A[i][i] = i;
        }
        for (i = 1; i < K; i++) {
            for (j = 0; j+i < K; j++) {
                dp[j][j+i] = MAX;
                    for (k = A[j][j+i-1]; k <=A[j+1][j+i]; k++) {
                        int temp;
                        if(j==0) temp = dp[j][k] + dp[k + 1][j + i] + p_sum[j + i];
                        else temp = dp[j][k] + dp[k + 1][j + i] + p_sum[j + i] - p_sum[j - 1];
 
                        if (dp[j][j + i] > temp) {
                            dp[j][j + i] = temp;
                            A[j][j + i] = k;
                        }
                    }
            }
        }
        printf("%d\n", dp[0][K - 1]);
    }
}
