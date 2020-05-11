#include<iostream>
using namespace std;
int main(){
    long long k,day=0,ans=0;
    scanf("%lld",&k);
    for(int i=1;i<=k;i++){
        for(int j=1;j<=i;j++){
            ans+=i;
            day++;
            if(day==k) break;
        }
        if(day==k) break;
    }
    printf("%lld\n",ans);
    return 0;
}