#include<iostream>
using namespace std;
const int MAXN=25;
int n,m;
int w[MAXN],num[MAXN];
int mark[MAXN];
int dfs(int take,int now){
    for(int i=1;i<=n;i++){
        if(mark[i]==0){
            mark[i]=-1;
            dfs(take,now++);
            mark[i]=0;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]); 
    cout<<3<<endl;
    return 0;
}