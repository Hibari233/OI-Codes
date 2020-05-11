#include<iostream>
using namespace std;
const int MAXN=10005;
long long n,s;
long long c[MAXN],y[MAXN];
long long ans=0;
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>y[i];
    }
    for(int i=2;i<=n;i++){
        c[i]=min(c[i-1]+s,c[i]);
    }
    for(int i=1;i<=n;i++){
        ans+=(c[i]*y[i]);
    }
    cout<<ans<<endl;
    return 0;
}