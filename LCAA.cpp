#pragma GCC optimize ("O3")
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500050,M=N*2;
int n,m,s,x,y;
int head[N],ver[M],Next[M],tot,par[N][25],depth[N];
void add(int x,int y){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}
void dfs(int x,int fa){
	depth[x]=depth[fa]+1;
	par[x][0]=fa;
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
		if(y==fa) continue;
		dfs(y,x);
	}
}
void getf(){
	for(int up=1;(1<<up)<=n;up++){
		for(int i=1;i<=n;i++){
			par[i][up]=par[par[i][up-1]][up-1];
		}
	}
}
int lca(int x,int y){
	if(depth[x]<depth[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(depth[par[x][i]]>=depth[y]) x=par[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--) if(par[x][i]!=par[y][i]) x=par[x][i],y=par[y][i];
	return par[x][0];
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(s,0);
	getf();
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}