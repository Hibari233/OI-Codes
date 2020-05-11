#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long T;
    cin>>T;
    for(long long i=1;i<=T;i++){
        long long n;
        cin>>n;
        if(n==1)
            cout<<n<<endl;
        else
            cout<<n*(n-1)<<endl;
    }
    return 0;
}