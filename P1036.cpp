#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=25;
int n,k,ans=0;
int num[MAXN];
int is_prime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int dfs(int total,int sum,int start,int end){
	if(total==k) return is_prime(sum);
	int ans=0;
	for(int i=start;i<=end;i++){
		ans+=dfs(total+1,sum+num[i],i+1,end);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	int res=dfs(0,0,1,n);
	printf("%d\n",res);
	return 0;
}