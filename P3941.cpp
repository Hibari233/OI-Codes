#include<iostream>
#include<cmath>
using namespace std;
const long long MAXN=505;
const long long MAXX=1000100;
long long sum_line[MAXN][MAXN];
long long sum_lines[MAXN];
long long mark[MAXX];
int main(){
    long long n,m,mod;
    long long ans=0;
    cin>>n>>m>>mod;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            cin>>sum_line[i][j];
            sum_line[i][j]=sum_line[i][j-1]+sum_line[i][j];
        }
    }
    for(long long i=1;i<=m;i++){
        for(long long j=i;j<=m;j++){
            for(long long k=1;k<=n;k++){
                sum_lines[k]=(sum_lines[k-1]+sum_line[k][j]-sum_line[k][i-1])%mod;
                mark[sum_lines[k]]=0;
            }
            for(long long k=1;k<=n;k++){
                if(!sum_lines[k]) ans++;
                ans+=mark[sum_lines[k]];
                mark[sum_lines[k]]++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}