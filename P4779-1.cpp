#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=100010,MAXM=500010;
struct Edge{
    int to,dis,next;
};
Edge edge[MAXM];
int head[MAXN],dis[MAXN],cnt;
bool vis[MAXN];
int n,m,s;
void add(int u,int v,int d){
    edge[++cnt].dis=d,edge[cnt].to=v,edge[cnt].next=head[u],head[u]=cnt;
}
struct node{
    int dis,pos;
    bool operator < (const node &x)const{
        return x.dis<dis;
    }
};
priority_queue<node> q;
void dijkstra(){
    dis[s]=0;
    q.push((node){0,s});
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        int x=tmp.pos,d=tmp.dis;
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=head[x];i;i=edge[i].next){
            int y=edge[i].to;
            if(dis[y]>dis[x]+edge[i].dis){
                dis[y]=dis[x]+edge[i].dis;
                if(!vis[y]) q.push((node){dis[y],y});
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n;i++) dis[i]=0x7fffffff;
    for(int i=1;i<=m;i++){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        add(u,v,d);
    }
    dijkstra();
    for(int i=1;i<=n;i++){
        printf("%d ",dis[i]);
    }
    printf("\n");
    return 0;
}