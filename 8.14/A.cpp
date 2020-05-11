#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=2050;
const int MAXM=10050;
int n,m,ans;
int vis[MAXN][MAXM];
int matched[MAXM];
bool mark[MAXM];
int maxx=-1;
void init(){
    for(int i=1;i<=MAXN;i++){
        for(int j=1;j<=MAXM;j++)
            vis[i][j]=-1;
    }
}
bool found(int x){
    for(int i=1;i<=maxx;i++){
        if(vis[x][i]==-1) continue;
        if(vis[x][i]!=0){
            if(mark[i]==true) continue;
            mark[i]=true;
            if(matched[i]==0||found(matched[i])!=false){
                matched[i]=x;
                return true;
            }
        }
    }
    return false;
}
void match(){
    int count=0;
    for(int i=1;i<=n;i++){
        memset(mark,false,sizeof(mark));
        if(found(i)!=false)
            count++;
    }
    ans=count;
}
int main(){
    cin>>n;
    init();
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        vis[i][y]=1;
        vis[i][x]=1;
        maxx=max(maxx,max(x,y));
    }
    match();
    cout<<ans<<endl;
    return 0;
}