#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN=55;
int m,n;
int graph[MAXN][MAXN];
int f[MAXN][MAXN][MAXN][MAXN];
int max_4ele(int a,int b,int c,int d){
	if(a<b) a=b;
	if(a<c) a=c;
	if(a<d) a=d;
	return a;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				for(int l=j+1;l<=m;l++){
					f[i][j][k][l]=max_4ele(f[i][j-1][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k][l-1],f[i-1][j][k-1][l])+graph[i][j]+graph[k][l];
				}
			}
		}
	}
	printf("%d\n",f[n][m-1][n-1][m]);
	return 0;
}
// f[i][j][k][l]=max{ f[i][j-1][k-1][l]
//					{ f[i-1][j][k][l-1]    +graph[i][j]+graph[k][j];
//					{ f[i][j-1][k][l-1]
//					{ f[i-1][j][k-1][l]