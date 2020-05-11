#pragma GCC optimize ("O3")
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
const long long MAXN=105;
const long long mod=998244353;
long long a[MAXN],n,m,ans=0;
queue<long long> q;
template<typename node>void read(node &a){
    node x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=0;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=((x<<1)%mod+(x<<3)%mod+ch-'0')%mod;
        ch=getchar();
    }
    a=f?x:mod-x;
}
bool check(long long num){
    long long total=a[0]%mod;
    num%=mod;
    long long x_pow=num%mod;
    for(int i=1;i<=n;i++){total+=a[i]*x_pow;x_pow=(x_pow*num)%mod;total%=mod;}
    if(total==0) return true;
    else return false;
}
int main(){
    read(n),read(m);
    for(int i=0;i<=n;i++) read(a[i]);
    for(int i=1;i<=m;i++){if(check(i)==true){q.push(i);ans++;}}
    printf("%lld\n",ans);
    while(q.size()!=0){printf("%lld\n",q.front());q.pop();}
    return 0;
}