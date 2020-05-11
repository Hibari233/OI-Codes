#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1000010;
int n,m;
int roadi[MAXN],roadj[MAXN];
int rq;
int u[MAXN],v[MAXN];
int s[MAXN];
int ans[MAXN];
inline void init(int n){
    for(int i=1;i<=n;i++)
        s[i]=i;
}
inline int find(int p){
    return s[p]=p==s[p]?p:find(s[p]);
}
inline void uni(int p,int q){
    int fp=find(p),fq=find(q);
    if(fp>fq)
        s[fp]=s[fq];
    else{
        s[fq]=s[fp];
    }
}
int main(){
    freopen("problem.in","r",stdin);
    freopen("problem.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>roadi[i]>>roadj[i];
    }
    cin>>rq;
    for(int i=1;i<=rq;i++){
        cin>>u[i]>>v[i];
    }


    init(n);
    for(int i=1;i<=m;i++){
        uni(roadi[i],roadj[i]);
        for(int j=1;j<=rq;j++){
            if(ans[j]!=0) continue;
            if(find(u[j])==find(v[j])){
                ans[j]=i;
            }
        }
    }
    for(int i=1;i<=rq;i++){
        if(ans[i]!=0){
            cout<<ans[i]<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}