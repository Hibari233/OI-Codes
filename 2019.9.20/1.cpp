#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int T;
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
    // n^k%p==ans; get(min(k));
    scanf("%d",&T);
    for(int o=1;o<=T;o++){
        long long p,n,ans,res=-1;
        scanf("%lld%lld%lld",&p,&n,&ans);
        for(int i=0;i<=100000;i++){
            if(quick_pow(n,i,p)==ans){
                res=i;
                break;
            }
        }
        if(res==-1) printf("-l");
        else printf("%lld\n",res);
    }
    return 0;
}