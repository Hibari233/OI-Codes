#include<iostream>
using namespace std;
const int MAXN=10050;
int maxx=-1;
int pos[MAXN];
int main(){
    int T,n;
    cin>>T;
    for(int p=1;p<=T;p++){
        maxx=-1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>pos[i];
        }
        for(int i=2;i<n;i++){
            int tmp=pos[i]-pos[i-1];
            maxx=max(maxx,tmp);
        }
        for(int i=n-2;i>=1;i--){
            int tmp=pos[i+1]-pos[i];
            maxx=max(maxx,tmp);
        }
        maxx--;
        cout<<maxx<<endl;
    }
    return 0;
}