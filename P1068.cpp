#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXN=5050;
int n,m,score,total=0;
struct __s{
    int num,p;
}s[MAXN];
bool cmp(__s x,__s y){
    if(x.p==y.p) return x.num<y.num;
    else return x.p>y.p;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&s[i].num,&s[i].p);
    make_heap(s+1,s+1+n,cmp);
    sort_heap(s+1,s+1+n,cmp);
    score=s[m*3/2].p;
    for(int i=1;i<=n;i++){
        if(s[i].p>=score) total++;
        else break;
    }
    printf("%d %d\n",score,total);
    for(int i=1;i<=total;i++){
        printf("%d %d\n",s[i].num,s[i].p);
    }
    return 0;
}