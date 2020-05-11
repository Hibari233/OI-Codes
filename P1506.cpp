#include<iostream>
using namespace std;
const int MAXN=505;
int n,m,ans=0;
char graph[MAXN][MAXN];
int xx[10]={1,-1,0,0};
int yy[10]={0,0,1,-1};
void dfs(int x,int y){
	if(graph[x][y]=='*') return;
	graph[x][y]='*';
	for(int i=0;i<=3;i++){
		if(x+xx[i]<1||x+xx[i]>n||y+yy[i]<1||y+yy[i]>m) continue;
		if(graph[x+xx[i]][y+yy[i]]=='*') continue;
		dfs(x+xx[i],y+yy[i]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>graph[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		if(i==1||i==n){
			for(int j=1;j<=m;j++){
				dfs(i,j);
			}
		}
		else{
			dfs(i,1);
			dfs(i,m);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(graph[i][j]=='0') ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}