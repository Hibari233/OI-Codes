#include<iostream>
using namespace std;
long long pow_(long long a,long long b,long long mod){
	long long ans=1,base=a;
	while(b>0){
		if(b&1)
			ans=(ans*base)%mod;
		(base*=base)%=mod;
		b>>=1;
	}
	return ans%mod;
}
int main(){
	long long b,p,k;
	cin>>b>>p>>k;
    long long ans=pow_(b,p,k);
	cout<<b<<'^'<<p<<" mod "<<k<<"="<<ans<<endl;
	return 0;
}