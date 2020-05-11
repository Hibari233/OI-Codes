#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
const int MAXN=35;
int n;
int graph[MAXN][MAXN];
int mark[MAXN][MAXN];
int dx[7]={0,0,1,-1};
int dy[7]={1,-1,0,0};
void dfs(int x,int y){
	mark[x][y]=true;
	for(int i=0;i<=3;i++){
		int xx=x+dx[i],yy=y+dy[i];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dfs(i,j);
		}
	}
}