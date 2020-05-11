#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct SegmentTree{
    long long l,r;
    long long sum,add;
}tree[4*200050];
long long a[200050],n,m;
void bulid(int p,int l,int r){
    tree[p].l=l,tree[p].r=r;
    if(l==r){tree[p].sum=a[l];return;}
    int mid=(l+r)/2;
    bulid(p*2,l,mid);
    bulid(p*2+1,mid+1,r);
    tree[p].sum=tree[p*2].sum+tree[p*2+1].sum;
}
void spread(int p){
    if(tree[p].add){
        tree[p*2].sum+=tree[p].add*(tree[p*2].r-tree[p*2].l+1);
        tree[p*2+1].sum+=tree[p].add*(tree[p*2+1].r-tree[p*2+1].l+1);
        tree[p*2].add+=tree[p].add;
        tree[p*2+1].add+=tree[p].add;
        tree[p].add=0;
    }
}
void change(int p,int l,int r,int d){
    if(l<=tree[p].l&&r>=tree[p].r){
        tree[p].sum+=(long long)d*(tree[p].r-tree[p].l+1);
        tree[p].add+=d;
        return;
    }
    spread(p);
    int mid=(tree[p].l+tree[p].r)/2;
    if(l<=mid) change(p*2,l,r,d);
    if(r>mid) change(p*2+1,l,r,d);
    tree[p].sum=tree[p*2].sum+tree[p*2+1].sum;
}
long long ask(int p,int l,int r){
    if(l<=tree[p].l&&r>=tree[p].r) return tree[p].sum;
    spread(p);
    int mid=(tree[p].l+tree[p].r)/2;
    long long val=0;
    if(l<=mid) val+=ask(p*2,l,r);
    if(r>mid) val+=ask(p*2+1,l,r);
    return val;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    bulid(1,1,n);
    for(int i=1;i<=m;i++){
        int option;
        scanf("%d",&option);
        if(option==1){
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            change(1,x,y,k);
        }
        else{
            int x,y;
            scanf("%d%d",&x,&y);
            long long ans=ask(1,x,y)>>2;
            printf("%lld\n",ans);
        }
    }
    return 0;
}