#include <iostream>
using namespace std;

bool ace[4], king[4], queen[4], jack[4], trump[4];
int cnt[4], points, sPoints, pos;
char tmp[4];
int main() {
	while (scanf("%s", tmp) == 1) {
		for (int i = 0; i < 4; i++) {
			ace[i] = king[i] = queen[i] = jack[i] = trump[i] = false;
			cnt[i] = 0;
		}

		points = sPoints = 0;


		for (int i = 0; i < 13; i++) {
			if (i != 0) scanf("%s", tmp);

			if (tmp[1] == 'S') pos = 0;
			else if (tmp[1] == 'H') pos = 1;
			else if (tmp[1] == 'D') pos = 2;
			else if (tmp[1] == 'C') pos = 3;

			if (tmp[0] == 'A') {
				ace[pos] = true;
				points += 4;
			}

			else if (tmp[0] == 'K') {
				king[pos] = true;
				points += 3;
			}

			else if (tmp[0] == 'Q') {
				queen[pos] = true;
				points += 2;
			}

			else if (tmp[0] == 'J') {
				jack[pos] = true;
				points += 1;
			}

			cnt[pos]++;
		}

		for (int i = 0; i < 4; ++i) {
			if (ace[i])
				trump[i] = true;

			if (king[i] && cnt[i] < 2) --points;
			else if (king[i]) trump[i] = true;

			if (queen[i] && cnt[i] < 3) --points;

			else if (queen[i]) trump[i] = true;

			if (jack[i] && cnt[i] < 4) --points;

			if (cnt[i] == 2) sPoints++;
			else if (cnt[i] < 2) sPoints += 2;
		}

		if (points >= 16 && trump[0] && trump[1] && trump[2] && trump[3])
			printf("BID NO-TRUMP\n");

		else if (points + sPoints >= 14) {
			char maxMark = 'S';
			int max = 0;
			for (int i = 1; i < 4; i++) {
				if (cnt[i] > cnt[max]) {
					max = i;
					if (max == 1) maxMark = 'H';
					else if (max == 2) maxMark = 'D';
					else if (max == 3) maxMark = 'C';
				}
			}
			printf("BID %c\n", maxMark);
		}
		else printf("PASS\n");
	}
	return 0;
}