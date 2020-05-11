#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=10005;
const int MAXM=1010005;
int head[2*MAXM],ver[2*MAXM],Next[2*MAXM];
int matched[2*MAXM];
int mark[MAXN*2];
int n,ans,tot,u,v;
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
void match(){
	for(int i=1;i<=n;i++){
		for(int i=1;i<=20020;i++) mark[i]=false;
		if(dfs(i)==true) ans++;
        else break;
	}
}
int main(){
	n=read();
    for(int i=1;i<=n;i++){
        int a=read(),b=read();
        add(a,i);
        add(b,i);
    }
	match();
    printf("%d\n",ans);
	return 0;
}