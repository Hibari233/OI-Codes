#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bits\stdc++.h>
using namespace std;
const int N=10000050;
int n,q;
int a[N];
int sum[N];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",sum[r]-sum[l-1]);
	}
	return 0;
}