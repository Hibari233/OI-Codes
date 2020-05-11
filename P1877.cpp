#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int MAXN=100;
const int MAXM=1000*100;
int n,beginlevel,maxlevel;
int c[MAXN];
int f[MAXN][MAXM];
int main(){
	scanf("%d%d%d",&n,&beginlevel,&maxlevel);
	f[0][beginlevel]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=maxlevel;j>=0;j--){
			if(j-c[i]>=0) f[i][j]=f[i][j]||f[i-1][j-c[i]];
			if(j+c[i]<=maxlevel) f[i][j]=f[i][j]||f[i-1][j+c[i]];
		}
	}
	for(int i=maxlevel;i>=0;i--){
		if(f[n][i]==1) {printf("%d",i);return 0;}
	}
	printf("-1\n");
	return 0;
}