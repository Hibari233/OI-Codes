#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#include<vector>
using namespace std;
const int MAXN=200050;
int n,t,minn=0x3f3f3f3f;
int ver[MAXN],Next[MAXN],head[MAXN],deg[MAXN],tot;
vector<int> top;
bool mark[MAXN];
void add(int x,int y){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot,deg[y]++;
}
void topsort(){
	queue<int> q;
	for(int i=1;i<=n;i++) if(deg[i]==0) q.push(i);
	while(q.size()){
		int x=q.front();q.pop();
		top.push_back(x);
		for(int i=head[x];i;i=Next[i]){
			int y=ver[i];
			if(!--deg[y]) q.push(y);
		}
	}
	for(int i=0;i<top.size();i++){
		mark[top[i]]=true;
	}
}
int dfs(int x){
	mark[x]=true;
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
		if(!mark[y]){
			return dfs(y)+1;
		}
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		add(i,t);
	}
	topsort();
	for(int i=1;i<=n;i++){
		if(!mark[i]){
			minn=min(minn,dfs(i));
		}
	}
	printf("%d\n",minn);
	return 0;
}