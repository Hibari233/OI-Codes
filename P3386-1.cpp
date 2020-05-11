#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=1005,M=N*2;
int n,m,e,ans,x,y;
int head[N],ver[M],Next[M],tot;
int matched[N];
bool mark[N];
void add(int x,int y){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}
bool dfs(int x){
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
		if(mark[y]) continue;
		mark[y]=true;
		if(!matched[y]||dfs(matched[y])){
			matched[y]=x;
			return true;
		}
	}
	return false;
}
void match(){
	for(int i=1;i<=n;i++){
		if(dfs(i)) ans++;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&e);
	for(int i=1;i<=e;i++){
		scanf("%d%d",&x,&y);
		if(x>n||y>m) continue;
		add(x,y);
	}
	match();
	printf("%d\n",ans);
	return 0;
}