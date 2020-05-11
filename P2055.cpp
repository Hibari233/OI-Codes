#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=2500;
const int MAXM=2500;
int head[MAXN],ver[MAXN],Next[MAXN];
int matched[MAXM];
int mark[MAXM];
int n,ans,tot,sum=0;
int in[MAXN];
int out[MAXN];
void init(){
    memset(head,0,sizeof(head));
    memset(matched,0,sizeof(matched));
    ans=0;
	sum=0;
	tot=0;
}
void add(int x,int y){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}
bool dfs(int x){
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
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
		if((in[i]&&!out[i])||!in[i]){
			memset(mark,false,sizeof(mark));
			if(dfs(i)) ans++;
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&in[i]);
			if(in[i]==0) sum++;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&out[i]);
			if(in[i]==1&&out[i]==0) sum++,add(i,i);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int g;
				scanf("%d",&g);
				if(g==1&&in[j]==1) add(i,j);
			}
		}
		match();
		if(ans==sum) printf("^_^\n");
		else printf("T_T\n");
	}
	return 0;
}