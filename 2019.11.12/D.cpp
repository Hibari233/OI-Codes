#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
const int MAXM=200020;
int n,m,tot,ans=0,total=0,s[MAXN];
struct node{
    int front,end,val;
}edge[MAXM];
void init(int n){for(int i=1;i<=n;i++) s[i]=i;}
int find(int x){return s[x]=x==s[x]?x:find(s[x]);}
bool cmp(node x,node y){return x.val<y.val;}
void kruskal(){
    for(int i=1;i<=m;i++){
        int v=find(edge[i].front),u=find(edge[i].end);
        if(v!=u){
            s[v]=u;
            ans+=edge[i].val;
            total++;
            if(total==n-1) break;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&edge[i].front,&edge[i].end,&edge[i].val);
		tot+=edge[i].val;
    }
    sort(edge+1,edge+1+m,cmp);
    kruskal();
    printf("%d\n",tot-ans);
    return 0;
}