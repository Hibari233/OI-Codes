#include<iostream>
using namespace std;
const int MAXN=1005;
int tri[MAXN][MAXN];
int dp[MAXN][MAXN];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>dp[i][j];
    //dp[n][n]=tri[n][n];
    for(int i=n-1;i>=1;i--){
        for(int j=i;j>=1;j--){
            dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    cout<<dp[1][1]<<endl;
    return 0;
}