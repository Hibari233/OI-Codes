#include<iostream>
using namespace std;
long long b,p,k,ans=0;
long long quick_pow(int a,int b,int mod){
    long long ans=1,base=a;
    while(b>0){
        if(b&1) ans=ans*base,ans%=mod;
        base*=base,base%=mod;
        b>>=1;
    }
    return ans%mod;
}
int main(){
    scanf("%lld%lld%lld",&b,&p,&k);
    ans=quick_pow(b,p,k);
    printf("%lld^%lld mod %lld=%lld\n",b,p,k,ans);
    return 0;
}