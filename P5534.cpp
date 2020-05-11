#include<iostream>
using namespace std;
long long f,s,n;
long long ans=0;
int main(){
	scanf("%lld%lld%lld",&f,&s,&n);
	long long cha=s-f;
	ans=f;
	for(int i=1;i<n;i++){
		f=f+cha;
		ans+=f;
	}
	printf("%lld",ans);
	return 0;
}