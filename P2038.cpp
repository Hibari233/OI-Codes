#include<iostream>
using namespace std;
const int MAXN=150;
int d,n,ans=-1,count=0;
int graph[MAXN][MAXN];
struct st{
	int x,y,k;
}cros[MAXN];
int calc(int x,int y){
	int sum=0;
	for(int i=x-d;i<=x+d;i++){
		for(int j=y-d;j<=y+d;j++){
			if(i<0||j<0||i>128||j>128) continue;
			sum+=graph[i][j];
		}
	}
	return sum;
}
int main(){
	scanf("%d%d",&d,&n);
	for(int i=1;i<=n;i++){
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		graph[x][y]=k;
	}
	for(int i=0;i<=128;i++){
		for(int j=0;j<=128;j++){
			int tmp=calc(i,j);
			if(tmp>ans) ans=tmp,count=0;
			if(ans==tmp) count++;
		}
	}
	printf("%d %d\n",count,ans);
	return 0;
}