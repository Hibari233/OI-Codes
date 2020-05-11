#include<iostream>
using namespace std;
const int MAXN=500020;
int a[MAXN],tree[MAXN],n,m;
int lowbit(int x){
    return x&-x;
}
void add(int x,int k){
    while(x<=n){
        tree[x]+=k;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x!=0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        add(i,a[i]);
    }
    for(int i=1;i<=m;i++){
        int mode;
        cin>>mode;
        if(mode==1){
            int x,k;
            cin>>x>>k;
            add(x,k);
        }
        if(mode==2){
            int x,y;
            cin>>x>>y;
            int ans=sum(y)-sum(x-1);
            cout<<ans<<endl;
        }
    }
    return 0;
}