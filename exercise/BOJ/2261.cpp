#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
struct P {
	int y, x;
};
bool cmpY(P a, P b) {
	return a.y < b.y;
}
bool cmpX(P a, P b) {
	return a.x < b.x;
}
int dist(P a, P b) {
	return (a.y - b.y) * (a.y - b.y) + (a.x - b.x)*(a.x - b.x);
}
P p[100005];
int N;

int getAnswer(P *point, int n) {
	if (n == 2) return dist(point[0], point[1]);
	if (n == 3) return min(min(dist(point[0], point[1]), dist(point[1], point[2])), dist(point[2], point[0]));

	int d = min(getAnswer(point, n / 2), getAnswer(point + n / 2, n - n / 2));
	int line = (point[n / 2 - 1].x + point[n / 2].x) / 2;

	vector<P> midArr; int midSize = 0;
	for (int i = 0; i < n; i++) {
		int td = line - point[i].x;
		if (td * td <= d) {
			midArr.push_back(point[i]);
		}
	}
	sort(midArr.begin(), midArr.end(), cmpY);
	int midN = midArr.size();
	for (int i = 0; i < midN; i++) {
		for (int j = i + 1; j < midN && j < i + 6; j++) {
			d = min(d, dist(midArr[i], midArr[j]));
		}
	}
	return d;
}
; int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf("%d%d", &p[i].x, &p[i].y);
	
	sort(p, p + N, cmpX);
	printf("%d\n", getAnswer(p, N));
	return 0;;
}