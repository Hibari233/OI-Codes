#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
const int N=100010,M=N*2;
int n,m,s,x,y,z;
int dis[N];
bool vis[N];
int head[N],ver[M],edge[M],Next[M],tot;
void add(int x,int y,int z){
	ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}
struct node{
	int dis,pos;
};
bool operator < (const node &x,const node &y){
	return x.dis>y.dis;
}
priority_queue<node> q;
void dijkstra(){
	dis[s]=0;
	q.push((node){0,s});
	while(!q.empty()){
		node tmp=q.top();q.pop();
		int x=tmp.pos;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=Next[i]){
			int y=ver[i];
			if(dis[y]>dis[x]+edge[i]){
				dis[y]=dis[x]+edge[i];
				if(!vis[y]) q.push((node){dis[y],y});
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	dijkstra();
	for(int i=1;i<=n;i++) printf("%d ",dis[i]);
	return 0;
}