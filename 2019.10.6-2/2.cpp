#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=300050;
int n;
int a[MAXN];
long long ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int minn=a[i];
		int maxx=a[i];
		for(int j=i-1;j>=1;j--){
			minn=min(minn,a[j]);
			maxx=max(maxx,a[j]);
			ans+=maxx-minn;
		}
	}
	printf("%lld\n",ans);
	return 0;
}