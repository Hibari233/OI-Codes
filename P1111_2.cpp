#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
const int MAXM=200020;
long long n,m,ans=-1,total,s[MAXN];
struct node{
    long long front,end,val;
};
node edge[MAXM];
inline long long find(int p){
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
    long long v,u;
    for(int i=1;i<=m;i++){
        v=find(edge[i].front);
        u=find(edge[i].end);
        //cout<<"v:"<<v<<" u:"<<u<<endl;
        if(v!=u){
            s[v]=u;
            ans=max(ans,edge[i].val);
            total++;
            //cout<<"total"<<total<<endl;
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
    for(int i=1;i<=m;i++)
        cin>>edge[i].front>>edge[i].end>>edge[i].val;
    stable_sort(edge+1,edge+1+m);
    kruskal();
    int judge;
    judge=find(1);
    for(int i=2;i<=n;i++){
        if(find(i)!=find(1)){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}