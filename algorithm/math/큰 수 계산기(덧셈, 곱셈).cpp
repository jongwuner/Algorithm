#define REP(i,a,b) for(int i = a; i < b; i++)
#define FOR(i,n) REP(i,0,n)

#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>

using namespace std;

string string_add(string a, string b) {
	string new_str = "";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string long_s;
	string short_s;
	if (a.size() >= b.size()) {
		long_s = a;
		short_s = b;
	}
	else {
		long_s = b;
		short_s = a;
	}
	int carry = 0;
	int dif = long_s.size() - short_s.size();
	FOR(i, dif)
		short_s += "0";
	FOR(i, long_s.size()) {
		int hab = stoi(long_s.substr(i, 1)) + stoi(short_s.substr(i, 1)) + carry;
		if (hab > 9) {
			carry = 1;
			hab -= 10;
		}
		else carry = 0;

		new_str += to_string(hab);
	}
	if (carry != 0) new_str += to_string(carry);
	reverse(new_str.begin(), new_str.end());
	return new_str;
}


string string_multi(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string acc = "0";
	FOR(i, a.size()) {
		int carry = 0;
		string gob = "";
		FOR(j, b.size()) {
			int gob_1 = stoi(a.substr(i, 1)) * stoi(b.substr(j, 1)) + carry;
			gob += to_string(gob_1 % 10);
			carry = gob_1 / 10;
		}
		if (carry != 0) gob += to_string(carry);
		FOR(j, i)
			gob = "0" + gob;
		reverse(gob.begin(), gob.end());
		acc = string_add(acc, gob);
	}
	return acc;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		string a, b;
		cin >> a >> b;
		cout << "ADD : " << string_add(a, b) << "\n";
		cout << "MUL : " << string_multi(a, b) << "\n";
	}

	return 0;
}