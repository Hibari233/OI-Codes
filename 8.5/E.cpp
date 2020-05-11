#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN=1005;
struct node{
    int Petra;
    int Jan;
};
node val[MAXN];
bool operator < (const node x,const node y){
    if(x.Petra==y.Petra) return x.Jan>y.Jan;
    else return x.Petra>y.Petra;
}
int total=0;
int dp[MAXN][MAXN];
int w[MAXN][MAXN];
int main(){
    int T;
    cin>>T;
    for(int p=1;p<=T;p++){
        total=0;
        int n;
        cin>>n;
        string first;
        cin>>first;
        for(int i=1;i<=n;i++){
            cin>>val[i].Petra>>val[i].Jan;
            total+=val[i].Petra;
        }
        sort(val+1,val+1+n);
        if(first=="Jan"){
            for(int i=1;i<=n-1;i++){
                for(int j=1;j<=(i+1)/2;j++){
                    if(dp[i-1][j]>=dp[i-1][j-1]+val[i+1].Jan){
                        dp[i][j]=dp[i-1][j];
                        w[i][j]=w[i-1][j];
                    }
                    else{
                        if(dp[i-1][j]==dp[i-1][j-1]+val[i+1].Jan){
                        dp[i][j]=dp[i-1][j];
                        w[i][j]=min(w[i-1][j-1]+val[i+1].Petra,w[i-1][j]);
                    }
                    else{
                        dp[i][j]=dp[i-1][j-1]+val[i+1].Jan;
                        w[i][j]=w[i-1][j-1]+val[i+1].Petra;
                        }
                    }
                }
            }
            cout<<w[n][(n+1)/2]<<" "<<dp[n][(n+1)/2]<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=(i+1)/2;j++){
                    if(dp[i-1][j]>dp[i-1][j-1]+val[i].Jan){
                        dp[i][j]=dp[i-1][j];
                        w[i][j]=w[i-1][j];
                    }
                    else{
                        if(dp[i-1][j]==dp[i-1][j-1]+val[i].Jan){
                        dp[i][j]=dp[i-1][j];
                        w[i][j]=min(w[i-1][j-1]+val[i].Petra,w[i-1][j]);
                    }
                    else{
                        dp[i][j]=dp[i-1][j-1]+val[i].Jan;
                        w[i][j]=w[i-1][j-1]+val[i].Petra;
                        }
                    }
                }
            }
            cout<<total-w[n][(n+1)/2]<<" "<<dp[n][(n+1)/2]<<endl;
        }
    }
}