#include<iostream>
using namespace std;
const int MAXN=100050;
const int MOD=1000000007;
int n,q;
int num[MAXN];
int sum[MAXN];
int count[MAXN];
long long quick_pow(int a,int b){
    long long base=a,ans=1;
    while(b>0){
        if(b&1) ans*=base,ans%=MOD;
        base*=base,base%=MOD;
        b>>=1;
    }
    return ans%MOD;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%1d",&num[i]);
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+num[i];
	}
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		long long x=sum[r]-sum[l-1];
		long long y=r-l+1-x;
		long long ans=((quick_pow(2,x)-1)*quick_pow(2,y))%MOD;
		printf("%lld\n",ans);
	}
}