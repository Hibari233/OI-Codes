#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=1005;
const int MAXM=1005;
int head[MAXN],ver[MAXN*MAXM],Next[MAXN*MAXM];
int matched[MAXM];
int mark[MAXM],lf[MAXN];
int n,m,ans,tot,u,v;
void add(int x,int y){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}
bool dfs(int x){
	for(int i=head[x];i;i=Next[i]){
		#define y ver[i]
		if(mark[y]==true) continue;
		mark[y]=true;
		if(matched[y]==0||dfs(matched[y])==true){
			matched[y]=x,lf[x]=y;
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
	scanf("%d%d",&n,&m);
    while(scanf("%d%d",&u,&v)){
        if(u==-1&&v==-1) break;
        add(u,v);
    }
	match();
	if(ans==0){
        printf("No Solution\n");
        return 0;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        if(lf[i]!=0) printf("%d %d\n",i,lf[i]);
    }
	return 0;
}