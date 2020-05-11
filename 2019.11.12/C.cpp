#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=20020;
const int MAXM=20020;
int n,m,total=0,tmp,s[MAXN];
struct node{
    int front,end,val;
}edge[MAXM];
struct st{
	int x,y;
}ans[MAXN];
void init(int n){for(int i=1;i<=n;i++) s[i]=i;}
int find(int x){return s[x]=x==s[x]?x:find(s[x]);}
bool cmp(node x,node y){return x.val<y.val;}
bool cmp1(st x,st y){if(x.x==y.x) return x.y<y.y;else return x.x<y.x;}
void kruskal(){
    for(int i=1;i<=m;i++){
        int v=find(edge[i].front),u=find(edge[i].end);
        if(v!=u){
            s[v]=u;
            total++;
			ans[total].x=edge[i].front,ans[total].y=edge[i].end;
            if(total==n-1) break;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=1;i<=m;i++) {scanf("%d%d%d",&edge[i].front,&edge[i].end,&edge[i].val);if(edge[i].front>edge[i].end)swap(edge[i].front,edge[i].end);}
    sort(edge+1,edge+1+m,cmp);
    kruskal();
	sort(ans+1,ans+total+1,cmp1);
	for(int i=1;i<=total;i++) printf("%d %d\n",ans[i].x,ans[i].y);
    return 0;
}