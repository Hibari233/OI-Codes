#include<iostream>
#include<cstdio>
using namespace std;
int num(int x){
    int count=0;
    while(x!=0){
        x=x/10;
        count++;
    }
    return count;
}
long long f(int x){
    long long ans=1;
    for(int i=1;i<=x;i++){
        ans*=i;
        while((ans/10)*10==ans){
            ans/=10;
        }
        int mod=num(i);
        ans=ans%(10*mod);
    }
    return ans%10;
}
int main(){
    freopen("brute.txt","w",stdout);
    for(int i=10000000;i<=10000100;i++){
        printf("%lld\n",f(i));
    }
    return 0;
}