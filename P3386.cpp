#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=1005;
const int MAXM=1005;
int head[MAXN],ver[MAXN*MAXM],Next[MAXN*MAXM];
int matched[MAXM];
int mark[MAXM];
int n,m,e,ans,tot;
void add(int x,int y){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}
bool dfs(int x){
	for(int i=head[x];i;i=Next[i]){
		#define y ver[i]
		if(mark[y]==true) continue;
		mark[y]=true;
		if(matched[y]==0||dfs(matched[y])==true){
			matched[y]=x;
			return true;
		}
	}
	return false;
}
void match(){
	for(int i=1;i<=n;i++){
		memset(mark,false,sizeof(mark));
		if(dfs(i)==true) ans++;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&e);
	for(int i=1;i<=e;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	match();
	printf("%d\n",ans);
	return 0;
}