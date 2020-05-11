#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=2005;
const int MAXM=2005;
int head[MAXN*2],ver[MAXN*MAXM*2],Next[MAXN*MAXM*2];
int matched[MAXM*2];
int mark[MAXM*2];
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
	for(int i=1;i<=n*2;i++){
		memset(mark,false,sizeof(mark));
		if(dfs(i)==true) ans++;
	}
}
int main(){
	scanf("%d",&n);
    for(int i=1;i<=n*2;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(i,v);
        add(i,u);
        add(i,n+v);
        add(i,n+u);
    }
    match();
    printf("%d\n",ans);
    return 0;
}