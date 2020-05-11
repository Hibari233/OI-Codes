#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=100;
int n,m,k,num=1,lake_total=0,ans=0,kk=1;
char graph[MAXN][MAXN];
bool mark[MAXN][MAXN],is=false;
int dx[6]={0,0,1,-1};
int dy[6]={1,-1,0,0};
struct st{
	int x,y,size;
}lake[MAXN*MAXN];
void dfs(int x,int y){
	if(x==1||x==n||y==1||y==m) is=true;
	lake[num].size++;
	mark[x][y]=true;
	for(int i=0;i<=3;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(x<1||x>n||y<1||y>m) continue;
		if(mark[xx][yy]==false&&graph[xx][yy]=='.'){
			dfs(xx,yy);
		}
	}
}
void dfs2(int x,int y){
	graph[x][y]='*';
	for(int i=0;i<=3;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(x<1||x>n||y<1||y>m) continue;
		if(graph[xx][yy]=='.'){
			dfs2(xx,yy);
		}
	}
}
bool operator < (const st &x,const st &y){
	return x.size<y.size;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",graph[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(graph[i][j]=='.'&&mark[i][j]==false){
				is=false;
				dfs(i,j);
				if(is==true){
					lake[num].size=0;
					continue;
				}
				lake[num].x=i;
				lake[num].y=j;
				lake_total++;
				num++;
			}
		}
	}
	sort(lake+1,lake+1+lake_total);
	while(lake_total>k){
		lake_total--;
		ans+=lake[kk].size;
		dfs2(lake[kk].x,lake[kk].y);
		kk++;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		printf("%s\n",graph[i]+1);
	}
	return 0;
}