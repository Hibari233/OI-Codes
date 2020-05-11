#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=510;
int n,m;
int city[MAXN][MAXN];
bool mark[MAXN][MAXN];
int l[MAXN][MAXN],r[MAXN][MAXN];
int xx[6]={0,0,1,-1};
int yy[6]={1,-1,0,0};
void init(){
    memset(l,0x3f,sizeof(l));
    for(int i=1;i<=m;i++){
        l[n][i]=r[n][i]=i;
    }
}
void dfs(int x,int y){
    mark[x][y]=true;
    for(int i=0;i<=3;i++){
        int __x=x+xx[i];
        int __y=y+yy[i];
        if(__x<1||__x>n||__y<1||__y>m) continue;
        if(city[__x][__y]>=city[x][y]) continue;
        if(!mark[__x][__y]) dfs(__x,__y);
        l[x][y]=min(l[x][y],l[__x][__y]);
        r[x][y]=max(r[x][y],r[__x][__y]);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&city[i][j]);
        }
    }
    for(int i=1;i<=m;i++){
        if(!mark[1][i]) dfs(1,i);
    }
    bool judge=false;
    int count=0;
    for(int i=1;i<=m;i++){
        if(mark[n][i]==false){
            judge=true;
            count++;
        }
    }
    if(judge==true){
        printf("0\n%d\n",count);
        return 0;
    }
    int x=1;
    while(x<=m){
        int maxx=-1;
        for(int i=1;i<=m;i++){
            if(l[1][i]<=x){
                maxx=max(r[1][i],maxx);
            }
        }
        count++;
        x=maxx+1;
    }
    printf("1\n%d\n",count);
    return 0;
}