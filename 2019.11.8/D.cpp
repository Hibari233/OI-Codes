#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;
bool dp[100000];
int T,n,a[N],ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=n;
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
		dp[0]=true;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(dp[a[i]]) {ans--;continue;}
			for(int j=a[i];j<=30000;j++){
				dp[j] |= dp[j-a[i]];
			}
		}
		printf("%d\n",ans);
	}
}