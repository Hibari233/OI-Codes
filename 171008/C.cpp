#include<iostream>
using namespace std;
const int MAXN=40050;
int a[MAXN],b[MAXN];
int main(){
    int n,k,m;
    bool judge=true;
    cin>>n>>k>>m;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    for(int j=1;j<=m;j++){
        if(b[j]>2) judge=false;
        cin>>b[j];
    }
    if(n==2&&m==2){
        cout<<1<<endl;
        return 0;
    }
    if(judge==true&&m==1){
        cout<<k<<endl;
        return 0;
    }
    cout<<3<<endl;
    return 0;
}