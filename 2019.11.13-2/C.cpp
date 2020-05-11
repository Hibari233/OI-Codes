#pragma GCC optimize ("O3")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int N=30;
int n,X,ans=0;
int a[N];
int calc(int x){
	int cnt=0;
	while(x!=0){
		cnt++;
		x=x&(x-1);
	}
	return cnt;
}
void dfs(int step,int total){
	if(total==X) {ans++;return;}
	if(step==n+1) return;
	for(int i=1;i<=3;i++){
		if(i==1){
			dfs(step+1,total);
		}
		if(i==2){
			dfs(step+1,total+a[step]);
		}
		if(i==3){
			int tmp=1<<calc(a[step]);
			dfs(step+1,total+tmp);
		}
	}
}
int main(){
	scanf("%d%d",&n,&X);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}