#include<iostream>
#include<cstdio>
#include<queue>
#include<memory.h>
using namespace std;
struct node{
	int x,y,s;
};
int t,n,m,stx,sty;
char a[210][210];
bool book[210][210];
int tx[5]={0,0,1,-1};
int ty[5]={1,-1,0,0};
int bfs(int x,int y){
	queue<node>q;
	node st;
	st.x=x;st.y=y;st.s=0;
	book[x][y]=1;
	q.push(st);
	while(q.size()){
		node now=q.front();
		q.pop();
		for(int i=0;i<=3;i++){
			int xx=now.x+tx[i];
			int yy=now.y+ty[i];
			int ss=now.s+1;
			if((!book[xx][yy])&&a[xx][yy]!='#'&&xx>=1&&xx<=n&&yy>=1&&yy<=m){
				book[xx][yy]=1;
				if(a[xx][yy]=='E')
					return ss;
				node to;
				to.x=xx;
				to.y=yy;
				to.s=ss;
				q.push(to);
			}
		}
	}
	return -1;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%s",a[i]+1);
		memset(book,0,sizeof book);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]=='S')
					stx=i,sty=j;
		int ans=bfs(stx,sty);
		if(ans==-1) printf("oop!\n");
		else printf("%d\n",ans);
	}
	return 0;
}