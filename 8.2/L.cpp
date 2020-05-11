#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1000000;
int ans=0;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(n%i==0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}