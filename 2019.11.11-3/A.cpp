#pragma GCC optimize ("O3")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int N=50050*2;
int n,m;
int mem[N];
int head[N],Next[N],ver[N],edge[N],tot,maxx;
int dp[N*2];
void add(int x,int y,int z){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot,edge[tot]=z;
}
int dfs(int x,int cur){
	int tmp=0;
	for(int i=head[x];i;i=Next[i]){
		if(edge[i]<=cur) continue;
		if(dp[i]>0){
			tmp=max(dp[i],tmp);
			continue;
		}
		dp[i]=dfs(ver[i],edge[i]);
		tmp=max(tmp,dp[i]);
	}
	return tmp+1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	int res=-1;
	for(int i=0;i<n;i++){
		res=max(res,dfs(i,-1));
	}
	printf("%d\n",res-1);
	return 0;
}