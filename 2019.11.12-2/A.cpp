#include<iostream>
using namespace std;
const int N=25;
int n,r;
int a[N];
bool book[N];
void dfs(int step,int cur){
	if(step==r){
		for(int i=0;i<step;i++){
			printf("%3d",a[i]);
		}
		printf("\n");
		return;
	}
	for(int i=cur;i<=n;i++){
		if(book[i]==true) continue;
		book[i]=true;
		a[step]=i;
		dfs(step+1,i);
		book[i]=false;
	}
}
int main(){
	scanf("%d%d",&n,&r);
	dfs(0,1);
	return 0;
}