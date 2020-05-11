#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=305;
const int MAXM=100005;
int n,m,s[MAXN],ans,total,maxn=-1;
struct node{
    int begin,end,val;
};
node edge[MAXM];
bool operator < (const node &x,const node &y){
    return x.val<y.val;
}
inline void init(int n){
	for(int i=1;i<=n;i++)
		s[i]=i;
}
inline int find(int p){
    return s[p]=p==s[p]?p:find(s[p]);
}
void kruskal(){
    int v,u;
    for(int i=1;i<=m;i++){
        v=find(edge[i].begin);
        u=find(edge[i].end);
        if(v!=u){
            if(edge[i].val>=maxn){
                maxn=edge[i].val;
            }
            s[v]=u;
            ans++;
            total++;
            if(total==n-1){
                break;
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    init(n);
    for(int i=1;i<=m;i++){
        cin>>edge[i].begin>>edge[i].end>>edge[i].val;
    }
    sort(edge+1,edge+1+m);
    kruskal();
    cout<<ans<<" "<<maxn<<endl;
    return 0;
}