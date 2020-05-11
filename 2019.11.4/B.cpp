#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000000;
const int mod = 1e8 - 3;
int n;
long long ans;
struct st
{
	int h, m;
} match1[MAXN], match2[MAXN];
int sorted[MAXN];
template <typename node>
void read(node &a)
{
	node x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = 0;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = ((x << 1) + (x << 3) + ch - '0');
		ch = getchar();
	}
	a = f ? x : -x;
}
bool operator<(const st &x, const st &y)
{
	return x.h < y.h;
}
int t[MAXN];
void merge(int l, int mid, int r)
{
	int i = l, j = mid, cnt = 0;
	while (i < mid && j < r)
	{
		if (sorted[i] <= sorted[j])
			t[cnt++] = sorted[i++];
		else
			t[cnt++] = sorted[j++], ans += mid - i;
	}
	while (i < mid)
		t[cnt++] = sorted[i++];
	while (j < r)
		t[cnt++] = sorted[j++];
	for (int i = 0; i < cnt; i++)
		sorted[l + i] = t[i];
}
void merge_sort(int l, int r)
{
	if (r - l <= 1)
		return;
	int mid = (l + r) >> 1;
	merge_sort(l, mid);
	merge_sort(mid, r);
	merge(l, mid, r);
}
int main()
{
	read(n);
	for (int i = 0; i < n; i++)
	{
		read(match1[i].h);
		match1[i].m = i;
	}
	for (int i = 0; i < n; i++)
	{
		read(match2[i].h);
		match2[i].m = i;
	}
	sort(match1, match1 + n);
	sort(match2, match2 + n);
	for (int i = 0; i < n; i++)
		sorted[match1[i].m] = match2[i].m;
	merge_sort(0, n);
	printf("%lld\n", ans % mod);
	return 0;
}