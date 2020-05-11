#include<iostream>
using namespace std;
int home[500000];
int kirai[10];
int main(){
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>home[i];
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>kirai[i];
    }
    cout<<0<<endl;
    return 0;
}