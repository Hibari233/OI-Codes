#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int N=200050;
int n,q,s,tmp;
int sum[N];
int main(){
	scanf("%d%d%d",&n,&q,&s);
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		if(tmp<=s) sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1];
	}
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",sum[r]-sum[l-1]);
	}
	return 0;
}