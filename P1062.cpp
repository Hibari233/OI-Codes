#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
long long k,n,ans=0;
deque<int> q;
int main(){
    scanf("%lld%lld",&k,&n);
    while(n){
        q.push_back(n&1);
        n>>=1;
    }
    while(q.size()){
        ans+=q.back()*pow(k,q.size()-1);
        q.pop_back();
    }
    printf("%lld\n",ans);
    return 0;
}