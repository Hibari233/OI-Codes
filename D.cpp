#include<iostream>
#include<cstdio>
const long long mod=10007;
typedef long long ll;
ll qpow(ll a,ll b)
using namespace std;
int a,b,k,n,m,dp[1100][1100];
int main(){
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	for(int i=1;i<=k;i++)
		dp[i][1]=dp[i][i+1]=1;
	for(int i=2;i<=k;i++)
		for(int j=2;j<=i;j++)
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
	ll ans=((qpow(a,n)+qpow(b,m))%mod+dp[k][m+1])%mod;
	printf("%lld\n",ans);
}