#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=500100;
int n,m,s,u,v;
int head[N],ver[N*2],Next[N*2],depth[N],par[N][25],tot;
void add(int x,int y){ver[++tot]=y,Next[tot]=head[x],head[x]=tot;}
void dfs(int x,int fa){
	depth[x]=depth[fa]+1;
	par[x][0]=fa;
	for(int i=head[x];i;i=Next[i]){
		if(ver[i]!=fa){
			dfs(ver[i],x);
		}
	}
}
void getf(){
	for(int up=1;(1<<up)<=n;up++){
		for(int i=1;i<=n;i++){
			par[i][up]=par[par[i][up-1]][up-1];
		}
	}
}
int lca(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	for(int i=20;i>=0;i--) if(depth[par[u][i]]>=depth[v]) u=par[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return par[u][0];
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(s,0);
	getf();
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
}