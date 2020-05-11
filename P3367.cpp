#include<cstdio>
int s[10005],n,m,j,p,q;
void init(int n){for(int i=1;i<=n;i++) s[i]=i;}
int find(int x){return s[x]=x==s[x]?x:find(s[x]);}
void uni(int x,int y){s[find(x)]=find(y);}
int main(){
	scanf("%d%d",&n,&m);
	init(n);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&j,&p,&q);
		if(j==1) uni(p,q);
		else if(find(p)==find(q)) printf("Y\n");
		else printf("N\n");
	}
	return 0;
}