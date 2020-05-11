#include<iostream>
using namespace std;
const int MAXN=50;
const int fx[]={0,-2,-1,1,2,2,1,-1,-2};
const int fy[]={0,1,2,2,1,-1,-2,-2,-1};
long long dp[MAXN][MAXN];
bool mark[MAXN][MAXN];

int main(){
    int bx,by,hx,hy;
    scanf("%d%d%d%d",&bx,&by,&hx,&hy);
    for(int i=1;i<=8;i++){
        if(hx+fx[i]<0||hy+fy[i]<0) continue;
        mark[hx+fx[i]][hy+fy[i]]=true;
    }
    mark[hx][hy]=true;
    dp[0][0]=1;
    for(int i=0;i<=bx;i++){
        for(int j=0;j<=by;j++){
            if(i==0&&j==0) continue;
            if(mark[i][j]!=true){
                if(i-1<0) dp[i][j]=dp[i][j-1];
                else if(j-1<0) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            else dp[i][j]=0;
        }
    }
    printf("%lld\n",dp[bx][by]);
    return 0;
}