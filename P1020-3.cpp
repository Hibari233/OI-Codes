#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int mis[MAXN];
int lis[MAXN];
int lds[MAXN];
int main(){
    int p=1;
    while(cin>>mis[p]){
        p++;
    }
    p--;
    int l1=1,l2=1;
    lis[1]=lds[1]=mis[1];

    for(int i=2;i<=p;i++){
        if(lds[l1]>=mis[i]) lds[++l1]=mis[i];
        else{
            int n=upper_bound(lds+1,lds+1+l1,mis[i],greater<int>())-lds;
            lds[n]=mis[i];
        }
        if(lis[l2]<mis[i]) lis[++l2]=mis[i];
        else{
            int n=lower_bound(lis+1,lis+1+l2,mis[i])-lis;
            lis[n]=mis[i];
        }
    }
    cout<<l1<<endl<<l2<<endl;
    return 0;
}