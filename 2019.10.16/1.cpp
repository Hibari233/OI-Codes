#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000;
int n,stx,sty,edx,edy;
int mark[MAXN][MAXN];
int graph[MAXN][MAXN];
int dx[7]={0,0,1,-1};
int dy[7]={1,-1,0,0};
int bfs(int x,int y){
	queue<int> qx,qy,step;
	qx.push(x),qy.push(y),step.push(0);
	mark[x][y]=true;
	while(qx.size()){
		int xx=qx.front();
		int yy=qy.front();
		int ss=step.front();
		qx.pop();
		qy.pop();
		step.pop();
		for(int i=0;i<=3;i++){
			int xxx=xx+dx[i];
			int yyy=yy+dy[i];
			int sss=ss+1;
			if(xxx<1||yyy<1||xxx>n||yyy>n) continue;
			if(mark[xxx][yyy]==false&&graph[xxx][yyy]==0){
				mark[xxx][yyy]=true;
				if(xxx==edx&&yyy==edy) return sss;
				qx.push(xxx);
				qy.push(yyy);
				step.push(sss);
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%1d",&graph[i][j]);
		}
	}
	scanf("%d%d%d%d",&stx,&sty,&edx,&edy);
	printf("%d\n",bfs(stx,sty));
	return 0;
}