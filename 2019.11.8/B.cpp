#include<cstdio>
#include<queue>
using namespace std;
const int N=200050;
int n,head[N],ver[N],Next[N],tot,deg[N];
bool mark[N];
int ans=0x3f3f3f3f;
void add(int x,int y){ver[++tot]=y,Next[tot]=head[x],head[x]=tot,deg[y]++;}
vector<int> top;
void topsort(){
	queue<int> q;
	for(int i=1;i<=n;i++) if(deg[i]==0) q.push(i);
	while(q.size()){
		int x=q.front();q.pop();
		top.push_back(x);
		for(int i=head[x];i;i=Next[i]){
			int y=ver[i];
			if(!--deg[y]) q.push(y);
		}
	}
	printf("%d",top.size());
	for(int i=0;i<top.size();i++){
		mark[top[i]]=true;
	}
}
int dfs(int x){
	mark[x]=true;
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
		if(mark[y]==false){
			return dfs(y)+1;
		}
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d",&tmp);
		add(i,tmp);
	}
	topsort();
	for(int i=1;i<=n;i++){
		if(mark[i]==false){
			ans=min(ans,dfs(i));
		}
	}
	printf("%d\n",ans);
	return 0;
}