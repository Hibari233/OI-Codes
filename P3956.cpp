#include<iostream>
using namespace std;
const int MAXN=1100;
int graph[MAXN][MAXN];
int s[MAXN][MAXN];
int ans=0x3f3f3f3f,m,n;
int tx[5]={0,0,1,-1};
int ty[5]={1,-1,0,0};
void init(int n){
    for(int i=1;i<=n+50;i++){
        for(int j=1;j<=n+50;j++){
            graph[i][j]=-1;
            s[i][j]=99999999;
        }
    }
}
void dfs(int x,int y,int total,bool cur){
    if(total>=s[x][y]) return;
    s[x][y]=total;
    if(x==m&&y==m){
        if(total<ans) ans=total;
        return;
    }
    for(int i=0;i<=3;i++){
        int c=graph[x][y];
        int xx=x+tx[i];
        int yy=y+ty[i];
        if(xx<1||xx>m||yy<1||yy>m) continue;
        if(graph[xx][yy]==0||graph[xx][yy]==1){
            if(graph[xx][yy]==c) dfs(xx,yy,total,true);
            if(graph[xx][yy]!=c) dfs(xx,yy,total+1,true);
        }
        else if(cur==true){
            graph[xx][yy]=c;
            dfs(xx,yy,total+2,false);
            graph[xx][yy]=-1;
        }
    }
}
int main(){
    cin>>m>>n;
    init(m);
    for(int i=1;i<=n;i++){
        int x,y,c;
        cin>>x>>y>>c;
        graph[x][y]=c;
    }
    dfs(1,1,0,true);
    if(ans==0x3f3f3f3f) ans=-1;
    cout<<ans<<endl;
}