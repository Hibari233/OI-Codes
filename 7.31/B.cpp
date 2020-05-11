#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=105;
struct node{
    int start,end;
};
node list[MAXN];
int last_time,ans;//0~23hour
bool operator < (const node &x,const node &y){
    return x.end<y.end;
}
int main(){
    while(1){
        ans=1;
        int n;
        cin>>n;
        if(n==0) break;
        for(int i=1;i<=n;i++){
            cin>>list[i].start>>list[i].end;
        }
        sort(list+1,list+1+n);
        last_time=list[1].end;
        for(int i=2;i<=n;i++){
            if(list[i].start>=last_time){
                last_time=list[i].end;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}