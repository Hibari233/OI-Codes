#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN=6005;
int n,x,y,root,val[MAXN],dp[MAXN][2],v[MAXN];
vector<int> master[MAXN];
void dfs(int x){
	dp[x][0]=0,dp[x][1]=val[x];
	for(int i=0;i<master[x].size();i++){
		int y=master[x][i];
		dfs(y);
		dp[x][0]+=max(dp[y][0],dp[y][1]);
		dp[x][1]+=dp[y][0];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	for(int i=1;i<=n-1;i++) {scanf("%d%d",&x,&y);master[y].push_back(x);v[x]=1;}
	//寻找树的树根
	for(int i=1;i<=n;i++) if(!v[i]) {root=i;break;}
	dfs(root);
	printf("%d\n",max(dp[root][0],dp[root][1]));
	return 0;
}