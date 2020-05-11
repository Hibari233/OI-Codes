#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int MAXR=1050;
const int MAXC=1050;
int r,c;
char graph[MAXR][MAXC];
bool mark[MAXR][MAXC];
int stx,sty,edx,edy;
int ans=0,minn=0x3f3f3f3f;
int xx[10]={0,1,0,-1};
int yy[10]={1,0,-1,0};
void dfs(int x,int y,bool get,int total){
	if(x==r&&y==c&&get==true){
		ans++;
		if(total<minn) minn=total;
	}
	if(graph[x][y]=='*') get=true;
	for(int i=0;i<=3;i++){
		if(x+xx[i]<1||x+xx[i]>r||y+yy[i]<1||y+yy[i]>c) continue;
		if(graph[x+xx[i]][y+yy[i]]=='X') continue;
		mark[x+xx[i]][y+yy[i]]=true;
		dfs(x+xx[i],y+yy[i],get,total+1);
		mark[x+xx[i]][y+yy[i]]=false;
	}
}
int main(){
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++){
		scanf("%s",graph[i]+1);
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(graph[i][j]=='@') stx=i,sty=j;
			if(graph[i][j]=='#') edx=i,edy=j;
		}
	}
	dfs(stx,sty,false,0);
	if(ans==0){
		printf("-1 0\n");
	}
	else{
		printf("%d %d\n",minn,ans);
	}
	return 0;
}