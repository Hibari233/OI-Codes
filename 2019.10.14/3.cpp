#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
const int MAXN=2000;
int n,m,q;
int graph[MAXN][MAXN],d[MAXN];
int x[MAXN],y[MAXN],z[MAXN];
bool v[MAXN];
void dijkstra(){
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[1]=0;
    for(int i=1;i<n;i++){
        int x=0;
        for(int j=1;j<=n;j++) if(!v[j]&&(x==0||d[j]<d[x])) x=j;
        v[x]=1;
        for(int y=1;y<=n;y++) d[y]=min(d[y],d[x]+graph[x][y]);
    }
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	memset(graph,0x3f,sizeof(graph));
	for(int i=1;i<=n;i++) graph[i][i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		graph[x[i]][y[i]]=min(graph[x[i]][y[i]],z[i]);
	}
	for(int i=1;i<=q;i++){
		int judge;
		scanf("%d",&judge);
		if(judge==1){
			int to;
			scanf("%d",&to);
			dijkstra();
			if(d[to]==0x3f3f3f3f) printf("-1\n");
			else printf("%d\n",d[to]);
		}
		else{
			int k;
			scanf("%d",&k);
			for(int i=1;i<=k;i++){
				int a;
				scanf("%d",&a);
				graph[x[a]][y[a]]++;
			}
		}
	}
	return 0;
}