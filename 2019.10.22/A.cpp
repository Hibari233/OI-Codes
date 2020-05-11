#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MOD=1e9+7;
int n;
long long quick_pow(int a,int b){
    long long ans=1,base=a;
    while(b>0){
        if(b&1) ans=ans*base,ans%=MOD;
        base*=base,base%=MOD;
        b>>=1;
    }
    return ans%MOD;
}
int main(){
	scanf("%d",&n);
	long long ans=(quick_pow(3,n+1)-1)*500000004%MOD;
	printf("%lld\n",ans);
	return 0;
}