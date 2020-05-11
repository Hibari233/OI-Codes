#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=200;
int graph[MAXN][MAXN];
int s[MAXN][MAXN]={0};
int m,n;
int ans=0x3f3f3f3f;
int xx[6]={0,0,1,-1};
int yy[6]={1,-1,0,0};
void init(int n){
    for(int i=1;i<=n+50;i++){
        for(int j=1;j<=n+50;j++){
            graph[i][j]=-1;
            s[i][j]=0x7f7f7f7f;
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
        int color=graph[x][y];
        int x_cur=x+xx[i];
        int y_cur=y+yy[i];
        if(x_cur<1||x_cur>m||y_cur<1||y_cur>m) continue;
        if(graph[x_cur][y_cur]==0||graph[x_cur][y_cur]==1){
            if(color==graph[x_cur][y_cur]) dfs(x_cur,y_cur,total,false);
            if(color!=graph[x_cur][y_cur]) dfs(x_cur,y_cur,total+1,false);
        }
        else if(cur==false){
            graph[x_cur][y_cur]=color;
            dfs(x_cur,y_cur,total+2,true);
            graph[x_cur][y_cur]=-1;
        }
    }
}
int main(){
    scanf("%d%d",&m,&n);
    init(m);
    for(int i=1;i<=n;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        graph[x][y]=z;
    }
    dfs(1,1,0,false);
    if(ans==0x3f3f3f3f) printf("-1");
    else{
        printf("%d",ans);
    }
    return 0;
}