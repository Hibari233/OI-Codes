#include<iostream>
using namespace std;
const int MAXN=100005;
int num[MAXN];
int f[MAXN];
int dp[MAXN];
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int n=1;
    while(cin>>num[n++]);
    n--;
    for(int i=1;i<=n;i++){
        f[i]=1;
        dp[i]=1;
    }
    int max_up=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            if(num[i]>num[j]){
                f[i]=max(f[i],f[j]+1);
            }
            if(f[i]>max_up) max_up=f[i];
        }
    }
    int max_down=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            if(num[i]<=num[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
            if(dp[i]>max_down) max_down=dp[i];
        }
    }
    cout<<max_down<<endl;
    cout<<max_up<<endl;
    return 0;
}