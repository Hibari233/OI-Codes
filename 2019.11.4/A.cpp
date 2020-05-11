#include<cstdio>
using namespace std;
int n,m,k,x;
long long quick_pow(long long a,long long b,long long mod){
	long long ans=1;
	while(b!=0){
		if(b&1) ans*=a,ans%=mod;
		b>>=1;
		a*=a,a%=mod;
	}
	return ans%mod;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&x);
	long long res=(x%n+m*quick_pow(10,k,n))%n;
	printf("%lld\n",res);
	return 0;
}