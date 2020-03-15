#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[] = { 1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K;
	cin >> K;
	cout << a[K - 1]<<"\n";
	return 0;
}