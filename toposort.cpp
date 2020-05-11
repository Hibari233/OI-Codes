#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=10000;
int ver[MAXN],Next[MAXN],head[MAXN],deg[MAXN],a[MAXN],tot,cnt,n,m;
void add(int x,int y){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot,deg[y]++;
}
void topsort(){
	queue<int> q;
	for(int i=1;i<=n;i++) if(deg[i]==0) q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		a[++cnt]=x;
		for(int i=head[x];i;i=Next[i]){
			int y=ver[i];
			if(--deg[y]==0) q.push(y);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	topsort();
	for(int i=1;i<=cnt;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}