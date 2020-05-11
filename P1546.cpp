#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
const int MAXM=105*105;
int graph[105][105];
int n,m,ans=0,total,s[MAXN];
struct node{
    int front,end,val;
};
node edge[MAXM];
inline int find(int p){
    return s[p]=p==s[p]?p:find(s[p]);
}
inline void init(int n){
	for(int i=1;i<=n;i++)
		s[i]=i;
}
bool operator <(const node &x,const node &y){
    return x.val<y.val;
}
void kruskal(){
    int v,u;
    for(int i=1;i<=m;i++){
        v=find(edge[i].front);
        u=find(edge[i].end);
        if(v!=u){
            s[v]=u;
            ans+=edge[i].val;
            total++;
            if(total==n-1){
                break;
            }
        }
    }
    return;
}
int main(){
    cin>>n;
    init(n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>graph[i][j];
    int cnt=1;
    int ignore=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=ignore)
                continue;
            if(graph[i][j]){
                edge[cnt].front=i;
                edge[cnt].end=j;
                edge[cnt].val=graph[i][j];
                cnt++;
            }
        }
        ignore++;
    }
    m=cnt;
    sort(edge+1,edge+1+cnt);
    kruskal();
    cout<<ans<<endl;
    return 0;
}