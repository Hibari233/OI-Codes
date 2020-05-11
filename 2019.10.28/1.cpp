#include<iostream>
using namespace std;
const int mod=1e9+7;
const int MAXN=1000050;
int n;
int dp[MAXN];
int main(){
	scanf("%d",&n);
	dp[0]=1;
	for(int i=0;(1<<i)<=n;i++){
		for(int j=(1<<i);j<=n;j++){
			dp[j]=(dp[j]+dp[j-(1<<i)])%mod;
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}