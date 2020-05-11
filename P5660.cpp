#include <cstdio>
int main() {
	char a; int ans = 0;
	while((a = getchar()) >= '0')
		if (a == '1') ans++;
	printf("%d\n", ans);
	return ans ^ ans;
}