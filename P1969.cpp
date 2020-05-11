#include<iostream>
using namespace std;
const int MAXN=1000050;
int num[MAXN];
int main(){
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    ans=num[1];
    for(int i=2;i<=n;i++){
        if(num[i]<=num[i-1]) continue;
        else{
            ans+=num[i]-num[i-1];
        }
    }
    cout<<ans<<endl;
    return 0;
}