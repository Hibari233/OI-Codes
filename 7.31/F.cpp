#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=300050;
int n;
int array[MAXN];
int max_k=0x3f3f3f3f;
int main(){
    //freopen("F.in","r",stdin);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>array[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(array[j]==0){
                max_k=0;
                cout<<max_k<<endl;
                return 0;
            }
            if(i==j) continue;
            int cur_k;
            cur_k=min(array[i],array[j])/abs(i-j);
            max_k=min(max_k,cur_k);
        }
    }
    cout<<max_k<<endl;
    return 0;
}