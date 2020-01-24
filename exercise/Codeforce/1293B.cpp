#include<iostream>
using namespace std;
double n, ans;
int main(){
	scanf("%lf", &n);
	for (int i = 1; i <= (int)n; i++) {
		ans += (double)1 / i;
	}
	printf("%.5lf\n", ans);
	return 0;
}