#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100;
int n,m;
bool ans=false;
char graph[MAXN][MAXN];
bool mark[MAXN][MAXN];
int dx[7]={0,0,1,-1};
int dy[7]={1,-1,0,0};
void dfs(int x,int y,int px,int py){
	if(mark[x][y]==true){
		ans=true;
		return;
	}
	mark[x][y]=true;
	for(int i=0;i<=3;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>m) continue;
		if(graph[xx][yy]==graph[x][y]){
			if(xx!=px||yy!=py){
				dfs(xx,yy,x,y);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",graph[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			memset(mark,false,sizeof(mark));
			dfs(i,j,0,0);
			if(ans==true){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}