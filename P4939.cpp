#include<iostream>
using namespace std;
const int MAXN=10000000;
int n,m;
int lowbit(int x){
    return x&-x;
}
int sum[MAXN],tree[MAXN];
int sum_(int x){
    int ans=0;
    while(x!=0){
        ans+=sum[x];
        x-=lowbit(x);
    }
    return ans;
}
void add(int x,int k){
    while(x<=n){
        sum[x]+=k;
        x+=lowbit(x);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int mode;
        cin>>mode;
        if(mode==0){
            int a,b;
            cin>>a>>b;
            add(a,1);
            add(b+1,-1);
        }
        if(mode==1){
            int a,ans=0;
            cin>>a;
            ans=sum_(a);
            cout<<ans<<endl;
        }
    }
    return 0;
}