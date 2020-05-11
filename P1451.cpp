#include<iostream>
using namespace std;
const int MAXN=105;
int m,n,ans=0;
int graph[MAXN][MAXN];
int xx[6]={0,0,1,-1};
int yy[6]={1,-1,0,0};
void dfs(int x,int y){
	if(x>m||y>n||x<1||y<1) return;
	graph[x][y]=0;
	for(int i=0;i<=3;i++){
		if(graph[x+xx[i]][y+yy[i]]){
			dfs(x+xx[i],y+yy[i]);
		}
	}
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%1d",&graph[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(graph[i][j])
				dfs(i,j),ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}