#pragma GCC optimize ("O3")
#include<cstdio>
#define min(x,y) (x<y?x:y)
#define N 1000100
long long n,m,ans=0x3f3f3f3f;
long long a[N];
signed main(){
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(long long k=1;k<=m;k++){
		long long b=0;
		for(long long i=1;i<n;i++){
			b+=min(((a[i+1]-a[i]+m)%m),((k-a[i+1]+m)%m+1));
		}
		ans=min((ans),(b));
	}
	printf("%lld\n",ans);
	return 0;
}