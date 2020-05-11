#include<iostream>
using namespace std;
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i*i<=n;i++){
        printf("%lld ",i*i);
    }
    printf("\n");
    return 0;
}