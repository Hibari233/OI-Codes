#include<iostream>
using namespace std;
const int MAXN=25;
int n,graph[MAXN][MAXN];
int book[MAXN];
int ans=-1;
void dfs(int i,int last){
    int sum=last;
    book[i]=true;
    for(int j=1;j<=n;j++){
        if(book[j]==true)
            sum-=graph[i][j];
        else sum+=graph[i][j];
    }
    if(ans<sum) ans=sum;
    if(sum>last){
        for(int k=i+1;k<=n;k++){
            dfs(k,sum);
            book[k]=false;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>graph[i][j];
        }
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}