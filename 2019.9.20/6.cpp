#include<iostream>
using namespace std;
long long quick_pow(int a,int b){
    long long ans=1,base=a;
    while(b>0){
        if(b&1) ans=ans*base;
        base*=base;
        b>>=1;
    }
    return ans;
}
int main(){
    long long m,t,num=0;
    unsigned long long exp=0;
    scanf("%d%d",&m,&t);
    while(m){
        num++;
        m=m-quick_pow(2,num-1);
        exp++;
    }
    printf("%llu\n",exp);
    return 0;
}