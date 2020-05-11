#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=30;
int graph[MAXN][MAXN];
int num[MAXN];
int path[MAXN],ans[MAXN],cnt;
bool mark[MAXN];
int n,max_ans;
bool check(int x){
    for(int i=1;i<=n;i++)
        if(graph[x][i]==1&&mark[i]==false) return true;
    return false;
}
void dfs(int pos,int step,int sum){
    if(check(pos)==false){
        if(max_ans<sum){
            max_ans=sum;
            cnt=step;
            for(int i=1;i<=step;i++) ans[i]=path[i];
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(graph[pos][i]==1&&mark[i]==false){
            mark[i]=true;
            path[step+1]=i;
            dfs(i,step+1,sum+num[i]);
            mark[i]=false;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        mark[i]=true;
        path[1]=i;
        dfs(i,1,num[i]);
        mark[i]=false;
    }
    for(int i=1;i<=cnt;i++)
        printf("%d ",ans[i]);
    printf("\n%d\n",max_ans);
    return 0;
}