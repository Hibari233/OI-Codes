#include<iostream>
using namespace std;
const int MAXN=100500000;
long long fib[MAXN],n;
int main(){
    scanf("%lld",&n);
    fib[1]=fib[2]=1;
    for(long long i=3;i<=n;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    printf("%lld\n",fib[n]);
    getchar();getchar();
    return 0;
}