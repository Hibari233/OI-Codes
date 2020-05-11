#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=105;
const int MAXM=105;
int n,m,ans=0;
char graph[MAXN][MAXM];
bool mark[MAXN][MAXM];
int xx[10]={-1,-1,-1,0,0,1,1,1};
int yy[10]={-1,0,1,-1,1,-1,0,1};
void dfs(int x,int y){
	if(mark[x][y]==true) return;
	if(graph[x][y]=='.') return;
	mark[x][y]=true;
	for(int i=0;i<=7;i++){
		if(x+xx[i]<1||x+xx[i]>n||y+yy[i]<1||y+yy[i]>m||graph[x+xx[i]][y+yy[i]]=='.') continue;
		dfs(x+xx[i],y+yy[i]);
	}
}
int main(){
	memset(mark,0,sizeof(mark));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>graph[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(graph[i][j]=='W'&&mark[i][j]==false)
				dfs(i,j),ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}