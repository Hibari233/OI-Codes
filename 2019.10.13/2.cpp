#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN=200;
int lake_total=0;
struct node{
	int num,squ,x,y;
}lake[MAXN*MAXN];
char graph[MAXN][MAXN];
bool mark[MAXN][MAXN],is;
int n,m,k,num=1,ans=0;
int xx[10]={0,0,1,-1};
int yy[10]={1,-1,0,0};
void dfs(int x,int y){
	if(x==1||x==n||y==1||y==m) is=true;
	lake[num].squ++;
	mark[x][y]=true;
	for(int i=0;i<=3;i++){
		int xxx=x+xx[i],yyy=y+yy[i];
		if(xxx<1||xxx>n||yyy<1||yyy>m) continue;
		if(graph[xxx][yyy]=='.'&&mark[xxx][yyy]==false){
			dfs(xxx,yyy);
		}
	}
}
void dfs_2(int x,int y){
	graph[x][y]='*';
	for(int i=0;i<=3;i++){
		int xxx=x+xx[i],yyy=y+yy[i];
		if(xxx<1||xxx>n||yyy<1||yyy>m) continue;
		if(graph[xxx][yyy]=='.'){
			dfs_2(xxx,yyy);
		}
	}
}
bool operator < (const node &x,const node &y){
	return x.squ<y.squ;
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
					lake[num].squ=0;
					continue;
				}
				lake[num].x=i;
				lake[num].y=j;
				lake_total++;
				num++;
			}
		}
	}
	sort(lake+1,lake+lake_total+1);
	int kk=1;
	while(lake_total>k){
		lake_total--;
		ans+=lake[kk].squ;
		kk++;
	}
	printf("%d\n",ans);
	for(int i=1;i<=kk-1;i++){
		dfs_2(lake[i].x,lake[i].y);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%c",graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}