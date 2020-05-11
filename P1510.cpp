#include<iostream>
using namespace std;
const int MAXN=1000050;
int dp[MAXN];
int vi[MAXN],ci[MAXN];
int main(){
    int v,n,c;
    scanf("%d%d%d",&v,&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&vi[i],&ci[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=c;j>=ci[i];j--){
            dp[j]=max(dp[j],dp[j-ci[i]]+vi[i]);
        }
    }
    if(dp[c]>=v){
        for(int i=0;i<=c;i++)
            if(dp[i]>=v){
                printf("%d\n",c-i);
                return 0;
            }
    }
    else{
        printf("Impossible\n");
    }
}