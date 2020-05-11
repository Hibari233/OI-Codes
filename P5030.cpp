#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int MAXN=205;
const int MAXM=205;
int n,m,k;
int graph[MAXN][MAXM];
struct Edge{
	int to,Next;
}edge[MAXN*MAXM*30];
int head[MAXN*MAXN],mark[MAXN*MAXN],matched[MAXN*MAXN];
int tot=0,ans=0;
const int xx[15]={-3,3,-3,3,-1,1,-1,1};
const int yy[15]={1,1,-1,-1,3,3,-3,-3};
bool chk(int x,int y){
	if(x>0&&y>0&&x<=n&&y<=m&&graph[x][y]==0) return true;
	return false;
}
void add(int u,int v){
	edge[++tot].to=v,edge[tot].Next=head[u],head[u]=tot;
}
bool dfs(int x){
	for(int i=head[x];i;i=edge[i].Next){
		int y=edge[i].to;
		if(mark[y]==true) continue;
		mark[y]=true;
		if(matched[y]==0||dfs(matched[y])==true){
			matched[y]=x;
			return true;
		}
	}
	return false;
}
void KM(){
	for(int i=1;i<=m*n;i++){
		memset(mark,false,sizeof(mark));
		if(dfs(i)) ans++;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		graph[u][v]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i&1||graph[i][j]) continue;
			for(int k=0;k<=7;k++){
				if(chk(i+xx[k],j+yy[k])==true) add((i-1)*m+j,(i+xx[k]-1)*m+j+yy[k]); 
			}
		}
	}
	KM();
	printf("%d\n",n*m-ans-k);
	return 0;
}