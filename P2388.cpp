#include<cstdio>
long long n,ans=0,s=0;
int main(){
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		long long tmp=i;
		while(tmp%5==0){
			s++;
			tmp/=5;
		}
		ans+=s;
	}
	printf("%lld\n",ans);
}