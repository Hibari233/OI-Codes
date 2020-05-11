#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5050;
int T,p;
long long c[MAXN][MAXN];
int quick_pow(int a,int b,int pow){
	long long ans=1,base=a;
	while(b){
		if(b&1) ans*=base,ans%=pow;
		base*=base,base%=pow;
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d",&T,&p);
	c[0][0]=1;
	for(int i=1;i<=5000;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
		}
	}
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		if(n==k) printf("%d\n",quick_pow(2,n,p));
		else{
			long long sum=0;
			for(int i=0;i<=k;i++){
				sum+=c[n][i],sum%=p;
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}