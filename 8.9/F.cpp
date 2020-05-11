#include<iostream>
using namespace std;
const long long MAXN=200050;
long long n,m;
long long mark[MAXN];
struct SegmentTree{
    long long l,r,dat;
}t[4*MAXN];
void build(long long p,long long l,long long r){
    t[p].l=l,t[p].r=r;
    if(l==r){
        t[p].dat=mark[l];
        return;
    }
    long long mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].dat=max(t[p*2].dat,t[p*2+1].dat);
}
void change(long long p,long long x,long long v){
    if(t[p].l==t[p].r){
        t[p].dat=v;
        return;
    }
    long long mid=(t[p].l+t[p].r)/2;
    if(x<mid) change(p*2,x,v);
    else change(p*2+1,x,v);
    t[p].dat=max(t[p*2].dat,t[p*2+1].dat);
}
long long ask(long long p,long long l,long long r){
    if(l>=t[p].l&&r>=t[p].r) return t[p].dat;
    long long mid=(t[p].l+t[p].r)/2;
    long long val=-(1<<30);
    if(l<=mid) val=max(val,ask(p*2,l,r));
    if(r>mid) val=max(val,ask(p*2+1,l,r));
    return val;
}
int main(){
    while(scanf("%lld%lld",&n,&m)!=2){
        for(long long i=1;i<=n;i++){
            scanf("%lld",&mark[i]);
        }
        build(1,1,n);
        while(m--){
            char judge[20];
            scanf("%s",judge);
            if(*judge=='Q'){
                long long l,r;
                scanf("%lld%lld",&l,&r);
                printf("%lld\n",ask(1,1,n));
            }
            else{
                long long id,point;
                scanf("%lld%lld",&id,&point);
                change(1,id,point);
            }
        }
    }
    return 0;
}