#include<cstdio>
#include<iostream>
using namespace std;
const int N=10000;
int n,m,ans=0,mark[N];
void init(int n){
	for(int i=1;i<=n;i++){
		mark[i]=1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	init(n);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y); 
	}
	printf("%d\n",ans);
	return 0;
}