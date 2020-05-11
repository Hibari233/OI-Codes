#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int MAXN=500020;
int tree[MAXN],n;
int lowbit(int x){
    return x&-x;
}
void add(int x,int k){
    while(x<=n){
        tree[x]+=k;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x!=0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int p=1;p<=T;p++){
        memset(tree,0,sizeof(tree));
        cout<<"Case "<<p<<":"<<endl;
        cin>>n;
        for(int i=1;i<=n;i++){
            int ai;
            cin>>ai;
            add(i,ai);
        }
        string order;
        while(true){
            cin>>order;
            if(order=="End"){
                break;
            }
            if(order=="Add"){
                int i,j;
                cin>>i>>j;
                add(i,j);
            }
            else if(order=="Sub"){
                int i,j;
                cin>>i>>j;
                j=-j;
                add(i,j);
            }
            else if(order=="Query"){
                int i,j;
                cin>>i>>j;
                int ans=sum(j)-sum(i-1);
                cout<<ans<<endl;
            }
        }
    }
}