#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MAXM=100050;
const int MAXN=20050;
int s[MAXN];
int book[MAXN]={0};
struct node{
    long long a,b,val;
}dat[MAXM];
bool cmp(node x,node y){
    return x.val>y.val;
}
void init(int n){
    for(int i=1;i<=n;i++) s[i]=i;
}
int find(int p){
    return p==s[p]?p:s[p]=find(s[p]);
}
void uni(int p,int q){
    s[find(p)]=s[find(q)];
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&dat[i].a,&dat[i].b,&dat[i].val);
    sort(dat+1,dat+1+m,cmp);
    for(int i=1;i<=m;i++){
        if(find(dat[i].a)==find(dat[i].b)){
            printf("%lld\n",dat[i].val);
            return 0;
        }
        else{
            if(book[dat[i].a]==0){
                book[dat[i].a]=dat[i].b;
            }
            if(book[dat[i].b]==0){
                book[dat[i].b]=dat[i].a;
            }
            uni(dat[i].a,book[dat[i].b]);
            uni(dat[i].b,book[dat[i].a]);
        }
    }
    printf("0\n");
    return 0;
}