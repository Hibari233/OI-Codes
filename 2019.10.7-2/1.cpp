#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int MAXN=100005;
long long T,n,ans=0,total=0;
struct node{
	long long a,h;
}m[MAXN];
bool operator < (const node x,const node y){
	return (x.h/x.a)>(y.h/y.a);
}
int main(){
	scanf("%lld",&T);
	while(T--){
		ans=0,total=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",&m[i].h,&m[i].a);
			total+=m[i].a;
		}
		sort(m+1,m+1+n);
		for(int i=1;i<=n;i++){
			long long att=1;
			while(m[i].h>0){
				ans+=total;
				m[i].h-=att;
				att++;
			}
			total-=m[i].a;
		}
		printf("%lld\n",ans);
	}
	return 0;
}