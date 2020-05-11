#include<iostream>
using namespace std;
const int MAXN=3500;
const int MAXM=13000;
int w[MAXM],d[MAXN];
int dp[MAXM];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>d[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}