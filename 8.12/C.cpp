#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=300005;
int head[MAXN],ver[MAXN],edge[MAXN],Next[MAXN],d[MAXN];
int m,tot;
int mark[MAXN];
bool judge=false;
queue<int> q;
bool v[MAXN];
int read(){
	int ans=0;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') ans=10*ans+ch-'0',ch=getchar();
	return ans;
}
void add(int x,int y,int z){
	ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}
void spfa(){
	mark[0]=1;
	memset(d,0,sizeof(d));
	memset(v,0,sizeof(v));
	v[0]=1;
	q.push(0);
	while(q.size()){
		int x=q.front();
		q.pop();
		v[x]=0;
		if(mark[x]==n-1){
			cout<<-1<<endl;
			judge=true;
			return;
		}
		mark[x]++;
		for(int i=head[x];i;i=Next[i]){
			int y=ver[i],z=edge[i];
			if(d[y]<d[x]+z){
				d[y]=d[x]+z;
				if(!v[y]) q.push(y),v[y]=1;
			}
		}
	}
}
int main(){
    int n=read(),k=read();
    for(int i=k;i>=1;i--){
        int x=read(),a=read(),b=read();
        if(x==1) add(a,b,0),add(b,a,0);
        else if(x==2){
			if(a==b){
				printf("%d\n",-1);
				return 0;
			}
			add(a,b,1);
		} 
		else if(x==3) add(b,a,0);
		else if(x==4){
			if(a==b){
				printf("%d\n",-1);
				return 0;
			}
			add(b,a,1);
		} 
		else if(x==5) add(a,b,0);
    }
	for(int i=n;i>=1;i--)
		add(0,i,1);
	spfa();
	if(judge==true) return 0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=d[i];
	}
	printf("%lld",ans);
	return 0;
}