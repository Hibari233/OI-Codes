#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int MAXN=2000;
int n,u,v,head[MAXN],ver[MAXN],Next[MAXN],tot=1;
bool aaa[MAXN];
int ans;
void add(int x,int y){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}
bool edge_mark[MAXN];
int total,vert;
int res=-1;
void dfs(int x,int fa,int cur){
	if(cur>total) total=cur,vert=x;
	for(int i=head[x];i;i=Next[i]){
		if(aaa[i])continue;
		int y=ver[i];
		if(y==fa) continue;
		dfs(y,x,cur+1);
	}
}
void dfs2(int x,int fa,int cur){
	if(cur>ans) ans=cur;
	for(int i=head[x];i;i=Next[i]){
		if(aaa[i])continue;
		int y=ver[i];
		if(y==fa) continue;
		dfs2(y,x,cur+1);
	}
}
int calc(int x){
	ans = total = -1;
	dfs(x,0,0);
	dfs2(vert,0,0);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++){
		for(int j=head[i];j;j=Next[j]){
			aaa[j]=aaa[j^1]=true;
			int first=calc(i);
			int second=calc(ver[j]);
			aaa[j]=aaa[j^1]=false;
			int sum=first*second;
			if(sum>res) res=sum;
		}
	}
	printf("%d\n",res);
	return 0;
}