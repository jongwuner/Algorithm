#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Matrix;
const ll mod = 1000000007;
ll n, m;
Matrix bm;
Matrix ansMat;
Matrix Mult (Matrix a, Matrix b){
	Matrix ans(m + 1, vector<ll>(m + 1));
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= m; j++) 
			for (int k = 1; k <= m; k++) 
				ans[i][j] = (ans[i][j] + (a[i][k] * b[k][j] % mod)) % mod;
	return ans;
}

Matrix getAnswer(ll N) {
	if (N == 1) return bm;
	Matrix tmpMatrix = getAnswer(N / 2);
	Matrix ans = Mult(tmpMatrix, tmpMatrix);
	if (N & 1) ans = Mult(ans, bm);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	bm.resize(m + 1, vector<ll>(m + 1, 0));
	bm[1][1] = bm[1][m] = 1;
	for (int i = 1; i < m; i++)
		bm[i + 1][i] = 1;
	ansMat = getAnswer(n);
	cout << ansMat[1][1] << "\n";
	return 0;
}