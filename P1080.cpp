#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int total,l,r;
}dat[1005];
bool operator < (const node &a,const node &b){
    return a.total<b.total;
}
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>dat[i].l>>dat[i].r;
        dat[i].total=dat[i].l*dat[i].r;
    }
    sort(dat+1,dat+1+n);
    int minn=-1;
    int k=a;
    for(int i=1;i<=n;i++){
        int cur=k/(dat[i].r);
        if(cur>minn) minn=cur;
        k*=dat[i].l;
    }
    cout<<minn<<endl;
    return 0;
}