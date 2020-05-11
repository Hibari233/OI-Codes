#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=105,M=N*105;
int t,n,m;
int val[N][N];
int dp[M*100];
int ans=0;
int main(){
	scanf("%d%d%d",&t,&n,&m);
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&val[j][i]);
		}
	}
	for(int k=1;k<t;k++){
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			for(int j=val[i][k];j<=m;j++){
				dp[j]=max(dp[j],dp[j-val[i][k]]+val[i][k+1]-val[i][k]);
			}
		}
		m+=dp[m];
	}
	printf("%d\n",m);
	return 0;
}