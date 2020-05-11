#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int MAXN=3*100010;
int n,ans,total[MAXN];
struct st{
    int na,t;
};
queue<st> q;
int main(){
    scanf("%d",&n);
    while(n--){
        int t,k;
        scanf("%d%d",&t,&k);
        for(int i=1;i<=k;i++){
            int tmp;
            scanf("%d",&tmp);
            if(total[tmp]==0) ans++;
            total[tmp]++;
            st u;
            u.na=tmp;
            u.t=t;
            q.push(u);
        }
        while(t-q.front().t>=86400){
            st u=q.front();
            total[u.na]--;
            if(total[u.na]==0) ans--;
            q.pop();
        }
        printf("%d\n",ans);
    }
}