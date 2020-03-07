#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
char S[8 * 100015];
const int START = 400000;
int sp = 400000;
int ep = 400000;
int Q, F, opt, state; // state:0 똑바로, state:1 바뀐상태
char mark;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin >> S + START >> Q;
	for (int i = sp; S[i]; i++)
		ep = i;
	ep += 1;


	while (Q--) {

		cin >> F;
	
		if (F == 1) {
			if (state == 0) state = 1;
			else state = 0;
		}
		else {
			cin >> opt >> mark;
			if ((opt == 1 && state == 0) || (opt == 2 && state == 1)) {
				sp--;
				S[sp] = mark;
			}
			if ((opt == 2 && state == 0) || (opt == 1 && state == 1)) {
				S[ep] = mark;
				ep++;
			}
		}
	}

	if (state == 0)
		cout << S + sp << "\n";
	else {
		for (int i = ep - 1; i >= sp; i--)
			cout << S[i];
		cout << "\n";
	}
	return 0;
}
