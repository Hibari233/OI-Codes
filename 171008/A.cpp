#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=450;
long long graph[MAXN][MAXN];
long long read(){
	long long ans=0;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') ans=10*ans+ch-'0',ch=getchar();
	return ans;
}
int main(){
    long long n,m,k;
    long long sum=0,ans=0;
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            graph[i][j]=read();
            graph[i][j]=graph[i][j]%k+graph[i-1][j]%k+graph[i][j-1]%k-graph[i-1][j-1]%k;
            graph[i][j]%=k;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int p=i;p<=n;p++){
                for(int l=j;l<=m;l++){
                    sum=0;
                    sum=(graph[p][l]-graph[i-1][l]-graph[p][j-1])+graph[i-1][j-1];
                    if(sum%k==0){
                        ans++;
                    }
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}