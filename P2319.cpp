#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=1050;
const int MAXM=1050;
int edge[MAXN][MAXM];
int matched[MAXM];
int lf[MAXN];
int mark[MAXM];
int n,m,ans;
bool dfs(int x){
    for(int i=0;i<m;i++){
        if(edge[x][i]!=0){
            if(mark[i]==true) continue;
            mark[i]=true;
            if(matched[i]==-1||dfs(matched[i])==true){
                matched[i]=x,lf[x]=i;
                return true;
            }
        }
    }
    return false;
}
void match(){
    for(int i=0;i<n;i++){
        memset(mark,false,sizeof(mark));
        if(dfs(i)==true) ans++;
        else break;
    }
}
int main(){
    scanf("%d%d",&m,&n);
    memset(matched,-1,sizeof(matched));
    for(int i=0;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        edge[i][v]=1;
        edge[i][u]=1;
    }
    match();
    printf("%d\n",ans);
    for(int i=0;i<ans;i++) printf("%d\n",lf[i]);
    return 0;
}