#include<iostream>
using namespace std;
const int MAXN=10005;
int n;
bool prime[MAXN],printed=false;
bool is_prime(int n){
	if(n==1) return false;
	if(n==2) return true;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) prime[i]=is_prime(i);
	for(int i=1;i<=n;i++){
		if(prime[i]==true&&prime[i+2]==true)
			{printf("%d %d\n",i,i+2);printed=true;}
	}
	if(printed==false) printf("empty\n");
	return 0;
}