#include<iostream>
#include<string>
using namespace std;
const int MAXN=100050;
int side[MAXN],a[MAXN],num[MAXN];
string job[MAXN];
int main(){
    int n,m;
    auto pos=1;
    cin>>n>>m;
    for(auto i=1;i<=n;i++){
        cin>>side[i]>>job[i];
    }
    for(auto i=1;i<=m;i++){
        cin>>a[i]>>num[i];
    }
    for(auto i=1;i<=m;i++){
        if(side[pos]==0){
            if(a[i]==0){
                if(pos>num[i]){
                    pos-=num[i];
                    continue;
                }
                if(pos<=num[i]){
                    pos=n-(num[i]-pos);
                    continue;
                }
            }
            if(a[i]==1){
                if(pos+num[i]>n){
                    pos=num[i]-(n-pos);
                    continue;
                }
                if(pos+num[i]<=n){
                    pos+=num[i];
                    continue;
                }
            }
        }
        else if(side[pos]==1){
            if(a[i]==1){
                if(pos>num[i]){
                    pos-=num[i];
                    continue;
                }
                if(pos<=num[i]){
                    pos=n-(num[i]-pos);
                    continue;
                }
            }
            if(a[i]==0){
                if(pos+num[i]>n){
                    pos=num[i]-(n-pos);
                    continue;
                }
                if(pos+num[i]<=n){
                    pos+=num[i];
                    continue;
                }
            }
        }
    }
    cout<<job[pos]<<endl;
    return 0;
}