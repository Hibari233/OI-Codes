#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=100005;
const int MAXM=1010005;
int head[2*MAXM],ver[2*MAXM],Next[2*MAXM];
int matched[2*MAXM];
int mark[MAXN*2];
int n,k,q,tot,u,v;
bool ans=true;
int read(){
    int ans=0;
    char ch;
    ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') ans=10*ans+ch-'0',ch=getchar();
    return ans;
}
void add(int x,int y){
    ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}
bool dfs(int x){
    for(int i=head[x];i;i=Next[i]){
        #define y ver[i]
        if(mark[y]==true) continue;
        mark[y]=true;
        if(matched[y]==0||dfs(matched[y])==true){
            matched[y]=x;
            return true;
        }
    }
    return false;
}
void match(int l,int r){
//	memset(mark,0,sizeof(mark));
    for(int i=l;i<=r;i++){
        for(int j=l;j<=r;j++) mark[j]=false;
        if(dfs(i)==false) {ans=false;return;}
    }
}
int main(){
    n=read(),k=read();
    for(int i=1;i<=k;i++){
        int a=read(),b=read();
        add(a,i);
        add(b,i);
    }
    q=read();
    for(int i=1;i<=q;i++){
        memset(matched,0,sizeof(matched));
        int l,r;
		ans=1;
        scanf("%d%d",&l,&r);
        match(l,r);
        if(ans==true) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}