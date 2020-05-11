#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXE=1e3+5;
int n,m,ans,ru[MAXE],vis[MAXE],pd[MAXE][MAXE];
int s[MAXE][MAXE];
queue<pair<int,int> > q;
vector<int> g[MAXE];
int read(){
    char ch;
    int ans=0;
    while(ch=getchar(),ch<'0'||ch>'9'); ans=ch-48;
    while(ch=getchar(),ch>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+ch-48;
    return ans;
}
void bfs(){
	for(int i=1;i<=n;i++) if(ru[i]==0) q.push(make_pair(i,1));
	ans=1;
	while(!q.empty()){
		int u=q.front().first,val=q.front().second;
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			ru[v]--;
			if(!ru[v]){
				q.push(make_pair(v,val+1));
				ans=max(ans,val+1);
			}
		}
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		s[i][0]=read();
		memset(vis,false,sizeof(vis));
		for(int j=1;j<=s[i][0];j++){
			int x=read();
			s[i][j]=x;
			vis[x]=true;
		}
		for(int j=s[i][1];j<=s[i][s[i][0]];j++){
			if(vis[j]) continue;
			for(int k=1;k<=s[i][0];k++){
				if(!pd[j][s[i][k]]){
					ru[s[i][k]]++;
					g[j].push_back(s[i][k]);
					pd[j][s[i][k]]=true;
				}
			}
		}
	}
	bfs();
	printf("%d\n",ans);
	return 0;
}