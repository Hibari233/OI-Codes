#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=100;
int num[MAXN];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    sort(num+1,num+1+n);
    int count=1;
    for(int i=2;i<=n;i++){
        if(num[i]==num[1])
            count++;
        else break;
    }
    if(count<=n/2) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
    return 0;
}