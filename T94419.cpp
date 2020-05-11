#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=1e6+7;
int num[MAXN],ans=0;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    for(int i=1;i<=n;i++)
        ans^=num[i];
    cout<<ans<<endl;
    return 0;
}