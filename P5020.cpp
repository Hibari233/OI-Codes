#pragma GCC optimize ("O3")
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
const int MAXN=105;
int T,n,a[MAXN];
bool dp[300000];
int ans;
int main(){
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof dp);
		scanf("%d",&n);
		ans=n;
		memset(a,0,sizeof a);
		dp[0]=true;
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		for(int i=0;i<n;i++){
			if(dp[a[i]]) {ans--;continue;}
			for(int j=a[i];j<=30000;j++){
				dp[j] |= dp[j-a[i]];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}