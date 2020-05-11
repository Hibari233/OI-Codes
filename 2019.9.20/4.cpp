#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=100010,MAXM=1000010;
struct Edge{
    long long to,dis,next;
};
Edge edge[MAXN];
int head[MAXN],dis[MAXN],cnt;
bool vis[MAXN];
int n,m,s,t,p;
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
int pre[MAXN];
deque<int> way;
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
            double dd=log((double)edge[i].dis);
            if(dis[y]>dis[x]+dd){
                dis[y]=dis[x]+dd;
                pre[y]=x;
                if(!vis[y]) q.push((node){dis[y],y});
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d%d",&n,&m,&s,&t,&p);
    for(int i=1;i<=n;i++) dis[i]=0x7fffffff;
    for(int i=1;i<=m;i++){
        long long u,v,d;
        scanf("%lld%lld%lld",&u,&v,&d);
        add(u,v,d);
        add(v,u,d);
    }
    dijkstra();
    int cur=t;
    long long res=1;
    way.push_back(t);
    while(cur!=s){
        way.push_back(pre[cur]);
        cur=pre[cur];
    }
    int pr=way.back();
    way.pop_back();
    while(way.size()){
        int yy=way.back();
        way.pop_back();
        for(int i=head[pr];i;i=edge[i].next){
            int y=edge[i].to;
            int z=edge[i].dis;
            if(y==yy) res*=z,res%=p;
        }
        pr=yy;
    }
    printf("%lld\n",res);
    return 0;
}