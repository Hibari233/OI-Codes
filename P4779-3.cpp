#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=200050,M=N*2;
int n,m,s,k,u,v;
int head[N],ver[M],Next[M],edge[M],tot,dis[N];
bool vis[N];
struct node{
	int dis,pos;
};
priority_queue<node> q;
bool operator < (const node &x,const node &y){
	return x.dis>y.dis;
}
void add(int x,int y,int k){
	ver[++tot]=y,edge[tot]=k,Next[tot]=head[x],head[x]=tot;
}
void dijkstra(){
	dis[s]=0;
	q.push((node){0,s});
	while(q.size()){
		node tmp=q.top();
		q.pop();
		int x=tmp.pos,d=tmp.dis;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=Next[i]){
			int y=ver[i];
			if(dis[y]>dis[x]+edge[i]){
				dis[y]=dis[x]+edge[i];
				if(!vis[y]){
					q.push((node){dis[y],y});
				}
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&k);
		add(u,v,k);
	}
	dijkstra();
	for(int i=1;i<=n;i++) printf("%d ",dis[i]);
	return 0;
}