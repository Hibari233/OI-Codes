#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const long long N=1000000;
const long long mod=1e9+7;
long long n;
long long a[N];
long long ans=0;
int main(){
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	long long now=n;
	if(n%2==1){
		long long cur=(n/2-1)*2+1;
		for(long long i=1;i<=n/2;i++){
			ans+=a[i]*now;
			ans%=mod;
			ans+=a[n-i+1]*now;
			ans%=mod;
			now+=cur;
			cur-=2;
		}
		long long mid=now;
		ans+=a[n/2+1]*mid;
	}
	if(n%2==0){
		long long cur=2*(n/2-1);
		for(long long i=1;i<=n/2;i++){
			ans+=a[i]*now;
			ans%=mod;
			ans+=a[n-i+1]*now;
			ans%=mod;
			now+=cur;
			cur-=2;
		}
	}
	ans%=mod;
	printf("%lld\n",ans);
	return 0;
}