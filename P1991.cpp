#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstdio>
using namespace std;
const int MAXN=505;
const int MAXM=200000;
int ss,p,s[MAXN],total;
int ct=1;
double ans=0;
struct node1{
    double x,y;
};
node1 pos[MAXN];
struct node{
    double begin,end,val;
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
    for(int i=1;i<=ct;i++){
        v=find(edge[i].begin);
        u=find(edge[i].end);
        if(v!=u){
            s[v]=u;
            //cout<<ans<<endl;
            ans=max(edge[i].val,ans);
            total++;
            if(total==p-ss){
                break;
            }
        }
    }
    return;
}
inline double dist(double x1,double y1,double x2,double y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int main(){
    cin>>ss>>p;
    for(int i=1;i<=p;i++){
        cin>>pos[i].x>>pos[i].y;
    }
    for(int i=1;i<=p-1;i++){
        for(int j=i+1;j<=p;j++){
            edge[ct].begin=i;
            edge[ct].end=j;
            edge[ct].val=dist(pos[i].x,pos[i].y,pos[j].x,pos[j].y);
            ct++;
        }
    }
    init(p);
    sort(edge+1,edge+ct);
    kruskal();
    printf("%.2lf",ans);
    return 0;
}