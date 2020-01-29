#include<iostream>
#include<vector>
#include<string>
using namespace std;
int T, N, maxVal, maxIdx;
const int pdiv[] = { 1, 4, 5, 7, 8, 9 };  
const int digit[] = { 2, 4, 5, 3, 7, 6 }; 
string S;
int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		// clear
		maxVal = -1000000;
		maxIdx = -1;
		S.clear();
		// init
		scanf("%d", &N); 
		if (N % 2 == 0) {
			for (int i = 0; i < N / 2; i++)
				S.push_back('1');
		}
		else {
			S.push_back('7');
			for (int i = 0; i < N / 2 - 1; i++)
				S.push_back('1');
		}
		cout << S << "\n";
	}
	return 0;
}