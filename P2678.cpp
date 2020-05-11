#include<iostream>
using namespace std;
const int MAXN=50050;
int stone[MAXN];
int ll,n,m,ans;
bool check(int mid){
    int count=0;
    int next=0;
    int cur=0;
    while(next<n+1){
        next++;
        if(stone[next]-stone[cur]<mid) count++;
        else cur=next;
    }
    if(count>m) return false;
    else return true;
}
int main(){
    cin>>ll>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>stone[i];
    }
    stone[n+1]=ll;
    int l=1;
    int r=ll;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)==true){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}