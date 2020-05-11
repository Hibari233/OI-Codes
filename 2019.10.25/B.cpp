#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000;
int n,m,ans;
int r[MAXN];
int d[MAXN],s[MAXN],t[MAXN],cf[MAXN];
bool check(int num){
	for(int i=1;i<=n;i++)
		cf[i]=r[i]-r[i-1];
	for(int i=1;i<=num;i++){
		cf[s[i]]-=d[i];
		cf[t[i]+1]+=d[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=cf[i];
		if(sum<0) return false;
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&r[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&d[i],&s[i],&t[i]);
	if(check(m)){
		printf("0\n");
		return 0;
	}
	int l=0,r=m;
	while(l<=r){
		int mid=l+((r-l)>>1);
		if(!check(mid)){
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	printf("-1\n%d",ans);
	return 0;
}