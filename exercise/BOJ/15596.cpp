#include <vector>
long long sum(std::vector<int> &a) {
	int n = a.size();
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		ret += a[i];
	}
	return ret;
}
