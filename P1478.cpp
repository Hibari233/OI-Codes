#include<iostream>
using namespace std;
const int MAXN=5005;
const int MAXS=1005;
int n,s,a,b;
int h[MAXN],ss[MAXN];
int dp[MAXS];
int main(){
	scanf("%d%d",&n,&s);
	scanf("%d%d",&a,&b);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&h[i],&ss[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=s;j>=ss[i];j--){
			if(h[i]<=a+b){
				dp[j]=max(dp[j],dp[j-ss[i]]+1);
			}
		}
	}
	printf("%d\n",dp[s]);
	return 0;
}