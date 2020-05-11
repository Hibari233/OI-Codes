#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
const int N=100010,M=500010;
struct edge{
	int ver,dis,next;
}e[M];
struct st{
	int dis,pos;
};
int head[N],dis[N],cnt;
bool vis[N];
int n,m,s;
priority_queue<st> q;
bool operator < (const st &x,const st &y){
	return x.dis<y.dis;
}
void add(int x,int y,int z){
	e[++cnt].dis=z,e[cnt].ver=y,e[cnt].next=head[x],head[x]=cnt;
}
void dijkstra(){
	dis[s]=0;
	q.push((st){0,s});
	while(q.size()){
		st tmp=q.top();
		q.pop();
		int x=tmp.pos,d=tmp.dis;
		if(vis[x]) continue;
		vis[x]=true;
		for(int i=head[x];i;i=e[i].next){
			int y=e[i].ver;
			if(dis[y]>dis[x]+e[i].dis){
				dis[y]=dis[x]+e[i].dis;
				if(!vis[y]) q.push((st){dis[y],y});
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	memset(dis,0x7f,sizeof dis);
	for(int i=1;i<=m;i++){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		add(u,v,d);
	}
	dijkstra();
	for(int i=1;i<=n;i++) printf("%d ",dis[i]);
	return 0;
}