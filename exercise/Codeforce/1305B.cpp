#include<bits/stdc++.h>
using namespace std;
string S;
int ans = 0;
int N;
priority_queue<int> pq;
int main() {
	cin >> S;
	int Lptr = 0, Rptr = S.size() - 1;
	N = S.size();
	while (Lptr < Rptr) {
		while (Lptr < N && S[Lptr] != '(') Lptr++;
		while (0 <= Rptr && S[Rptr] != ')') Rptr--;
		
		if (!(Lptr < Rptr && S[Lptr] == '(' && S[Rptr] == ')')) break;
		ans++;
		pq.push(-(Lptr + 1)); 
		pq.push(-(Rptr + 1));
		Lptr++; Rptr--;
	}
	if (ans > 0) cout << "1\n" << 2 * ans << "\n";
	else cout << "0\n";
	while (!pq.empty()) {
		cout << -pq.top() << " ";
		pq.pop();
	}
	cout << "\n";
	return 0;
}