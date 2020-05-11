#include<iostream>
#include<cstdio>
using namespace std;
int biao1=6,check1=10000000;
int biao2=2,check2=20000000;
int biao3=8,check3=30000000;
int biao4=4,check4=40000000;
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
    int start=1;
    if(x>=10000000){
        ans=biao1;
        start=check1;
    }
    if(x>=20000000){
        ans=biao2;
        start=check2;
    }
    if(x>=30000000){
        ans=biao3;
        start=check3;
    }
    if(x>=40000000){
        ans=biao4;
        start=check4;
    }
    for(int i=start;i<=x;i++){
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
    freopen("right.txt","w",stdout);
    for(int i=10000000;i<=10000100;i++){
        printf("%lld\n",f(i));
    }
    return 0;
}