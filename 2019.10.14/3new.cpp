#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;
const int MAXN=2000;
int n,m,qq;
struct Edge{
    int to,dis,next;
};
Edge edge[MAXN];
int head[MAXN],dis[MAXN],cnt;
bool vis[MAXN];
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
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
    dis[1]=0;
    q.push((node){0,1});
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
	scanf("%d%d%d",&n,&m,&qq);
	for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	for(int i=1;i<=qq;i++){
		int judge;
		scanf("%d",&judge);
		if(judge==1){
			int to;
			scanf("%d",&to);
			if(dis[to]==0x3f3f3f3f) printf("-1\n");
			else printf("%d\n",dis[to]);
		}
		else{
			int k;
			scanf("%d",&k);
			for(int i=1;i<=k;i++){
				int a;
				scanf("%d",&a);
				edge[a].dis++;
				dijkstra();
			}
		}
	}
	return 0;
}