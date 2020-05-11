#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int MAXN=2000;
int graph[MAXN][MAXN],d[MAXN],n,m,s;
bool v[MAXN];
void dijkstra(){
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[s]=0;
    for(int i=1;i<n;i++){
        int x=0;
        for(int j=1;j<=n;j++) if(!v[j]&&(x==0||d[j]<d[x])) x=j;
        v[x]=1;
        for(int y=1;y<=n;y++) d[y]=min(d[y],d[x]+graph[x][y]);
    }
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	memset(graph,0x3f,sizeof(graph));
	for(int i=1;i<=n;i++) graph[i][i]=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		graph[x][y]=min(graph[x][y],z);
	}
	dijkstra();
	for(int i=1;i<=n;i++) printf("%d ",d[i]);
	printf("\n");
	return 0;
}