#include<iostream>
#include<cstdio>
using namespace std;
const long long MAXN=200100;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long n,m,s,y,ans=inf,w[MAXN],v[MAXN];
long long total[MAXN],total_v[MAXN],maxx=-1,minn=inf,ql[MAXN],qr[MAXN];
long long labs(long long a,long long b){
    long long s=a-b;
    return s>0?s:(-s);
}
bool check(long long mid){
    for(long long i=1;i<=n;i++){
        total[i]=total[i-1];
        total_v[i]=total_v[i-1];
        if(w[i]>=mid){
            total[i]++;
            total_v[i]+=v[i];
        }
    }
    y=0;
    for(int i=1;i<=m;i++) y+=(total[qr[i]]-total[ql[i]-1])*(total_v[qr[i]]-total_v[ql[i]-1]);
    if(y>s) return true;
    else return false;
}
int main(){
    scanf("%lld%lld%lld",&n,&m,&s);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&w[i],&v[i]);
        maxx=max(w[i],maxx),minn=min(w[i],minn);
    }
    for(int i=1;i<=m;i++) scanf("%lld%lld",&ql[i],&qr[i]);
    long long l=minn,r=maxx;
    long long mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid-1;
        if(labs(y,s)<ans) ans=labs(y,s);
    }
    printf("%lld\n",ans);
}