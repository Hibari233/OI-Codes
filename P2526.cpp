#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200;
struct node{
	int x,y;
}M[MAXN],D[MAXN];
int graph[MAXN][MAXN];
int matched[MAXN];
bool mark[MAXN];
int n,m,ans=0;
int abs(int x){return x<0?-x:x;}
double dis(node x,node y){
	double a=abs(x.x-y.x),b=abs(x.y-y.y);
	return sqrt(a*a+b*b);
}
bool dfs(int x){
	for(int i=1;i<n;i++){
		if(graph[x][i]==1){
			if(mark[i]==true) continue;
			mark[i]=true;
			if(matched[i]==0||dfs(matched[i])==true){
				matched[i]=x;
				return true;
			}
		}
	}
	return false;
}
void match(){
	for(int i=1;i<=m;i++){
		memset(mark,false,sizeof(mark));
		if(dfs(i)) ans++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&M[i].x,&M[i].y);
	for(int i=1;i<=m;i++) scanf("%d%d",&D[i].x,&D[i].y);
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			if(dis(M[i],M[i+1])>(dis(M[i],D[j])+dis(D[j],M[i+1]))/2.0) graph[j][i]=1;
		}
	}
	match();
	printf("%d\n",ans+n);
	for(int i=1;i<=n;i++){
		printf("%d %d",M[i].x,M[i].y);
		if(i==n) printf("\n");
		else{
			printf(" ");
			if(matched[i]) printf("%d %d ",D[matched[i]].x,D[matched[i]].y);
		}
	}
	return 0;
}