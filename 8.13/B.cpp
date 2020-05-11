#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
long long ans;
int n,k;
int main()
{
  	scanf("%d%d",&n,&k);
  	ans=(long long)min(n,k)*(long long)k;
  	if(n>k) ans+=(long long)(n-k)*(long long)k;
  	int l=1;
  	while(l<=min(k,n)){
   	 	int x=k/(k/l);
		x=min(x,n);
   		long long res=(long long)(l+x)*(long long)(x-l+1)/2*(long long)(k/x);
   		ans-=res;
		l=x+1;
 	}
  	printf("%lld\n",ans);
  	return 0;
}
