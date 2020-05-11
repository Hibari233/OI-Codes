#include<iostream>
using namespace std;
const int MAXN=1005;
int x[MAXN],y[MAXN];
int n,m,total=0;
char graph[MAXN][MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>graph[i][j];
			if(graph[i][j]=='*') x[i]++,y[j]++,total++;
		}
	}
	if(total==0){
		printf("YES\n1 1\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(graph[i][j]=='*'){
				if(x[i]+y[j]-1==total){
				printf("YES\n");
				printf("%d %d\n",i,j);
				return 0;
				}
			}
			else if(x[i]+y[j]==total){
				printf("YES\n");
				printf("%d %d\n",i,j);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}