#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1000050;
int n,m,k,ans;
vector<int> edge[MAXN];
bool mark[MAXN];
int cnt;
void dfs(int x,int pre){
	if(mark[x]==true) {cnt++;return;}
	mark[x]=true;
	for(int i=0;i<edge[x].size();i++){
		if(edge[x][i]==pre) continue;
		dfs(edge[x][i],x);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(mark[i]==false){
			dfs(i,0);
			ans++;
		}
	}
	if(k==0) printf("%d\n",ans);
	else if(cnt==0) printf("%d\n",ans+k);
	return 0;
}