#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=500;
int n,v,c[MAXN*MAXN],w[MAXN*MAXN];
int dp[13000];
int main(){
	scanf("%d%d",&n,&v);
	for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&w[i]);
	for(int i=1;i<=n;i++){
		for(int j=v;j>=c[i];j--){
			dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
		}
	}
	printf("%d\n",dp[v]);
	return 0;
}