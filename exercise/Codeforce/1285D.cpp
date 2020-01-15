#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int MAX = 1e5 + 5;

int n, a[MAX];

int minV(int st, int en, int bt) {
	int mid = -1;
	for (int i = st; i <= en - 1; i++)
		if ((a[i] & (1 << bt)) != (a[i + 1] & (1 << bt)))
			mid = i;

	if (bt == -1) return 0;
	if (mid == -1)
		return minV(st, en, bt - 1);
	else
		return (1 << bt) + min(minV(st, mid, bt - 1), minV(mid + 1, en, bt - 1));

}

int main() {
	FAST;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	int ans = minV(0, n - 1, 29);
	cout << ans << '\n';
}