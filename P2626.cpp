#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=60;
#define MOD 2147483648
long long fib[MAXN];
int n;
int main(){
	fib[1]=fib[2]=1;
	scanf("%d",&n);
	for(int i=3;i<=n;i++){
		fib[i]=(fib[i-1]+fib[i-2])%MOD;
	}
	bool ju=false;
	printf("%lld=",fib[n]);
	for(int k=2;k<=fib[n];){
		if(fib[n]%k==0){
			if(ju==false) {printf("%d",k);ju=true;}
			else printf("*%d",k);
			fib[n]/=k;
		}
		else{
			k++;
		}
	}
	return 0;
}