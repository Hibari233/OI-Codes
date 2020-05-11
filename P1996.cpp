#include<iostream>
using namespace std;
const int MAXN=10050;
bool mark[MAXN];
int main(){
    int n,m,ct=0,pos=0;
    cin>>n>>m;
    while(ct!=n){
        if(pos+m<=n){
            pos+=m;
        }
        else{
            pos=m-(n-pos);
        }
        
        if(mark[pos]==false&&pos!=0){
            cout<<pos<<" ";
            mark[pos]=true;
            pos++;
        }
        if(mark[pos]==true){
            if(pos<=n-1) pos++;
            else pos=0;
        }
    }
    return 0;
}