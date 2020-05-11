#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=10050;
int n,m,w,x,y;
int c[N],d[N],s[N];
int ww[N],vv[N];
int dp[N*10];
void init(int n){for(int i=1;i<=n;i++)s[i]=i;}
int find(int x){return s[x]=x==s[x]?x:find(s[x]);}
void uni(int x,int y){s[find(x)]=find(y);}
int main(){
	scanf("%d%d%d",&n,&m,&w);
	init(n);
	for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&d[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		uni(x,y);
	}
	for(int i=1;i<=n;i++){
		ww[find(i)]+=c[i];
		vv[find(i)]+=d[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=w;j>=ww[i];j--){
			dp[j]=max(dp[j],dp[j-ww[i]]+vv[i]);
		}
	}
	printf("%d\n",dp[w]);
	return 0;
}