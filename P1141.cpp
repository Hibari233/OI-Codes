#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1005;
int n,m,ans=0,curr=1;
int graph[MAXN][MAXN];
bool mark[MAXN][MAXN];
int res[MAXN][MAXN];
int ress[100005];
int dx[8]={0,0,1,-1};
int dy[8]={1,-1,0,0};
void dfs(int x,int y,int cur){
	res[x][y]=curr;
	ans++;
	cur=graph[x][y];
	mark[x][y]=true;
	for(int i=0;i<=3;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>n) continue;
		if(mark[xx][yy]==true) continue;
		if(graph[xx][yy]!=cur){
			dfs(xx,yy,graph[xx][yy]);
		}
	}
}
int main(){
	memset(res,0,sizeof(res));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%1d",&graph[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(res[x][y]!=0){
			printf("%d\n",ress[res[x][y]]);
			continue;
		}
		curr=i;
		ans=0;
		dfs(x,y,graph[x][y]);
		ress[curr]=ans;
		printf("%d\n",ans);
	}
}