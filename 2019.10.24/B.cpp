#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN=200005;
const int MOD=10007;
int n,val[MAXN];
int ver[MAXN],Next[MAXN],head[MAXN],tot,maxx=-1,sum;
void add(int x,int y){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	for(int i=1;i<=n;i++){
		for(int j=head[i];j;j=Next[j])
			for(int k=head[i];k;k=Next[k]){
				if(j==k) continue;
				maxx=max(maxx,val[ver[j]]*val[ver[k]]);
				sum=(sum+val[ver[j]]*val[ver[k]])%MOD;
			}
	}
	printf("%d %d\n",maxx,sum);
	return 0;
}