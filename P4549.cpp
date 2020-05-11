#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=25;
int a[MAXN];
int main(){
    int n,ans=0;
    cin>>n;
    for(auto i=1;i<=n;i++){
        cin>>a[i];
        a[i]=abs(a[i]);
        ans=__gcd(a[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}