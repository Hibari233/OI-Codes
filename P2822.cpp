#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=2005;
int c[MAXN][MAXN],s[MAXN][MAXN];
int t,k,n,m;
void calc(){
    c[1][1]=1;
    for(int i=0;i<=2000;i++) c[i][0]=1;
    for(int i=2;i<=2000;i++){
        for(int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
        }
    }
    for(int i=2;i<=2000;i++){
            for(int j=1;j<=i;j++){
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
                if(c[i][j]==0) s[i][j]+=1;
            }
            s[i][i+1]=s[i][i];
        }
}
int main(){
    scanf("%d%d",&t,&k);
    calc();
    for(int i=1;i<=t;i++){
        scanf("%d%d",&n,&m);
        if(m>n) m=n;
        printf("%d\n",s[n][m]);
    }
    return 0;
}