#include<iostream>
using namespace std;
const int MAXN=1005;
int art[MAXN];
bool book[MAXN];
int bok[MAXN]={0};
int mem=0;
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=0;i<=1005;i++){
        book[i]=false;
    }
    for(int i=1;i<=n;i++){
        cin>>art[i];
    }
    int cur=1;
    int pop=1;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(book[art[i]]==true){
            continue;
        }
        else{
            if(mem==m){
                book[bok[pop]]=false;
                pop++;
                mem--;
                //cout<<bok[pop]<<endl;
                //cout<<book[bok[pop]]<<endl;
            }
            book[art[i]]=true;
            bok[cur++]=art[i];
            //cout<<art[i]<<endl;
            mem++;
            ans++;
            
        }
    }
    cout<<ans<<endl;
    return 0;
}