#include<iostream>
using namespace std;
const int MAXN=1050;
int s[MAXN];
int n,m,ans=0;
void init(int n){
    for(int i=1;i<=n;i++)
        s[i]=i;
}
int find(int p){
    if(p==s[p]) return p;
    return s[p]=find(s[p]);
}
void uni(int p,int q){
    int fp=find(p),fq=find(q);
    s[fp]=fq;
}
int main(){
    while(scanf("%d",&n)!=EOF&&n!=0){
        //cout<<n<<endl;
        init(n);
        scanf("%d",&m);
        if(m==0){
            ans=n-1;
            printf("%d\n",ans);
            continue;
        }
        ans=0;
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            uni(x,y);
        }
        for(int i=1;i<=n;i++){
            if(i==find(i))
                ans++;
        }
        printf("%d\n",ans-1);
    }
    return 0;
}