#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50050;
long long ll,n,m,l,r,ans;
long long stone[MAXN];
long long len[MAXN];
bool check(int x){
	long long count=0,cur=0,nxt=0;
	while(nxt<=n){
		if(stone[++nxt]-stone[cur]<x) count++;
		else cur=nxt;
	}
	if(count>m) return false;
	else return true;
}
int main(){
	scanf("%lld%lld%lld",&ll,&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&stone[i]);
	stone[n+1]=ll;
	l=0,r=ll;
	while(l<=r){
		long long mid=(r+l)/2;
		if(check(mid)==true){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	printf("%lld\n",ans);
}