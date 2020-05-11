#include<iostream>
using namespace std;
const int MAXN=15;
int n,m,ans=0x3f3f3f3f;
int graph[MAXN][MAXN];
int stx,sty,edx,edy;
int xx[7]={0,0,1,-1};
int yy[7]={1,-1,0,0};
void dfs(int x,int y,int hp,int step){
	//printf("%d %d %d\n",x,y,hp);
	if(hp<=0) return;
	if(step>=n*m) return;
	if(hp==1&&graph[x][y]==0) return;
	if(graph[x][y]==4) hp=6;
	if(x==edx&&y==edy) ans=min(ans,step);
	if(step>ans) return;
	for(int i=0;i<=3;i++){
		if(x+xx[i]<1||x+xx[i]>n||y+yy[i]<1||y+yy[i]>m) continue;
		if(graph[x+xx[i]][y+yy[i]]==0) continue;
		dfs(x+xx[i],y+yy[i],hp-1,step+1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&graph[i][j]);
			if(graph[i][j]==2) stx=i,sty=j;
			if(graph[i][j]==3) edx=i,edy=j;
		}
	}
	dfs(stx,sty,6,0);
	if(ans==0x3f3f3f3f) printf("-1");
	else printf("%d\n",ans);
	return 0;
}