#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000000;
int n,m,ans=0;
int fib[MAXN];
int main(){
    scanf("%d%d",&n,&m);
    fib[1]=fib[2]=1;
    for(int i=3;i<=m;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    ans=__gcd(fib[n],fib[m]);
    if(ans>=10000000) ans%=10000000;
    printf("%d\n",ans);
    return 0;
}