#include<cstdio>
#include<cstring>
#define MAXN 100010
#define P 1000000007
int n,k,now,sum;
int head[MAXN],Next[MAXN<<1],ver[MAXN<<1],tot;
int crowd[MAXN];
long long ans[MAXN];
int x,y;
void add(){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
	ver[++tot]=x,Next[tot]=head[y],head[y]=tot;
}
void dfs(int x,int fa,int dep){
	if(dep>k) return;
	crowd[x]=1;
	sum++;
	for(int i=head[x];i;i=Next[i]){
		if(ver[i]==fa) continue;
		dfs(ver[i],x,dep+1);
		crowd[x]+=crowd[ver[i]];
	}
	ans[now]=ans[now]*crowd[x]%P;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add();
	}
	for(now=1;now<=n;now++){
		memset(crowd,0,sizeof(crowd));
		sum=0;
		ans[now]=1;
		dfs(now,0,0);
		if(now==n) printf("%d\n",sum);
		else printf("%d ",sum);
	}
	for(int i=1;i<=n;i++){
		if(i==n) printf("%lld",ans[i]);
		else printf("%lld ",ans[i]);
	}
	return 0;
}