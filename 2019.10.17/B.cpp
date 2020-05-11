#include<iostream>
using namespace std;
int n;
bool Is_prime(int n){
    if(n==1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}
int main(){
	scanf("%d",&n);
	if(n<=2) printf("1\n");
	else printf("2\n");
	for(int i=2;i<=n+1;i++){
		if(Is_prime(i)==true) printf("1");
		else printf("2");
		if(i!=n+1) printf(" ");
	}
	printf("\n");
	return 0;
}