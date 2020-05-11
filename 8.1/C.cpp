#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long num;
long long ans=0;
long long c[10];
void init(){
    for(int i=1;i<=8;i++)
        c[i]=0;
}
void divide(long long n){
    init();
    while(n%2==0) n/=2,c[2]++;
    while(n%3==0) n/=3,c[3]++;
    while(n%5==0) n/=5,c[5]++;
    while(n%7==0) n/=7,c[7]++;
    ans=(c[2]+1)*(c[3]+1)*(c[5]+1)*(c[7]+1);
    cout<<ans<<endl;
}
int main(){
    while(cin>>num){
        if(num==0) return 0;
        divide(num);
    }
    return 0;
}