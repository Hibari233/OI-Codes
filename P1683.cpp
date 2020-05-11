#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int MAXN=25;
int w,h,ans;
char graph[MAXN][MAXN];
int stx,sty;
int dx[7]={0,0,1,-1};
int dy[7]={1,-1,0,0};
void dfs(int x,int y){
	//printf("%d %d\n",x,y);
	ans++;
	graph[x][y]='#';
	for(int i=0;i<=3;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1||yy<1||xx>h||yy>w) continue;
		if(graph[xx][yy]=='.')
			dfs(xx,yy);
	}
}
int main(){
	scanf("%d%d",&w,&h);
	for(int i=1;i<=h;i++){
		scanf("%s",graph[i]+1);
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(graph[i][j]=='@'){
				stx=i,sty=j;
			}
		}
	}
	dfs(stx,sty);
	printf("%d\n",ans);
	return 0;
}