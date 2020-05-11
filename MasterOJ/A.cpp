#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100050;
int n,q,s,l,r;
int h[N];
int sum[N];
int main(){
	scanf("%d%d%d",&n,&q,&s);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
		if(h[i]<=s) sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1];
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&l,&r);
		int ans=sum[r]-sum[l-1];
		printf("%d\n",ans);
	}
	return 0;
}
/*
前缀和
作用：区间内求和
好处：节省时间
如何实现前缀和
1.前缀和数组 int sum[10000];
2.给读入的数据进行处理
 对 a[]这个数组进行前缀和处理
 for(int i=1;i<=n;i++){
	sum[i]=sum[i-1]+a[i];
 }
3. l r 求从l到r这个区间的和
   int ans=sum[r]-sum[l-1];

实践：
a      1 2 3 4 5
sum  0 1 3 6 10 15
Q:  l=1 r=5 ans=sum[5]-sum[0];
*/