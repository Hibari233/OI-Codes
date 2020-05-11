#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=105;
int T,n,ans=0;
char graph[MAXN][MAXN];
bool mark[MAXN][MAXN];
int stx,sty,edx,edy;
int dx[7]={0,0,1,-1};
int dy[7]={1,-1,0,0};
struct st{
	int x,y;
};
int bfs(int x,int y){
	queue<st> q;
	st now;
	now.x=x,now.y=y;
	q.push(now);
	mark[x][y]=true;
	while(q.size()){
		for(int i=0;i<=3;i++){
			int xx=q.front().x+dx[i],yy=q.front().y+dy[i];
			if(xx<0||yy<0||xx>=n||yy>=n) continue;
			//printf("%d %d\n",xx,yy);
			if(mark[xx][yy]==false&&graph[xx][yy]=='.'){
				mark[xx][yy]=true;
				if(xx==edx&&yy==edy){
					return 1;
				}
				st now1;
				now1.x=xx,now1.y=yy;
				q.push(now1);
			}
		}
		q.pop();
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		memset(mark,0,sizeof(mark));
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",graph[i]);
		}
		scanf("%d%d%d%d",&stx,&sty,&edx,&edy);
		ans=bfs(stx,sty);
		if(ans==1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}