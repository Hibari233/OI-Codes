#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const int MAXM=100000;
int s[MAXN];
int f[MAXN];
struct st{
    int x;
    int y;
    int t;
};
st road[MAXM];
bool operator<(const st &x,const st &y){
    return x.t<y.t;
}
inline void init(int n){
    for(int i=1;i<=n;i++)
        s[i]=i;
}
inline int find(int p){
    return s[p]=p==s[p]?p:find(s[p]);
}
inline void uni(int p,int q){
    int fp=find(p),fq=find(q);
    s[fp]=s[fq];
    }
int main(){
    int n,m,time=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>road[i].x>>road[i].y>>road[i].t;
    sort(road,road+m);
    init(n);
    for(int i=0;i<m;i++){
        uni(road[i].x,road[i].y);
        int check=find(1);
        int judge=false;
        for(int j=1;j<=n;j++){
            f[j]=find(j);
        }
        for(int j=1;j<=n;j++)
            cout<<f[j]<<" ";
        cout<<endl;
        for(int j=1;j<=n;j++){
            if(check!=find(j)){
                judge=false;
                time=road[i].t;
                break;
            }
            else judge=true;
        if(judge==true)
            cout<<time<<endl;
            return 0;
        }
    }
    return 0;
    /*
    for(int i=0;i<m;i++)
        cout<<road[i].t<<" ";
    cout<<endl;
    */
}