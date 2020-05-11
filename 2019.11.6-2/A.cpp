#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=2050;
int n,k;
char graph[MAXN][MAXN];
char ans[MAXN*2+50]={0};
int cnt=0;
void dfs(int x,int y,int step){
	if(x==n&&y==n) {ans[step]=graph[x][y];return;}
	if(ans[step]>=graph[x][y]||ans[step]==0) ans[step]=graph[x][y];
	else return;
	if(x+1>n) dfs(x,y+1,step+1);
	else if(y+1>n) dfs(x+1,y,step+1);
	else if(graph[x+1][y]>graph[x][y+1]) dfs(x,y+1,step+1);
	else if(graph[x+1][y]<graph[x][y+1]) dfs(x+1,y,step+1);
	else if(graph[x+1][y]==graph[x][y+1]){dfs(x+1,y,step+1);dfs(x,y+1,step+1);}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%s",graph[i]+1);
	dfs(1,1,1);
	for(int i=1;i<=2*n-1;i++) printf("%c",ans[i]);
	return 0;
}