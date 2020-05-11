#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long x,y;
void exgcd(long long a,long long b){
    if(!b){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b);
    long long tx=x;
    x=y;
    y=tx-a/b*y;
}
int main(){
    long long a,b;
    scanf("%d%d",&a,&b);
    exgcd(a,b);
    while(x<0){
        x+=b;
    }
    x%=b;
    printf("%lld\n",x);
    return 0;
}
// ax+by=1

100000 3
3 7
5 11
