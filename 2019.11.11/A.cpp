#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int N=10050;
int n,m,p;
int l[N],r[N];
int head[N],ver[N],Next[N],tot;
void add(int x,int y){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++) scanf("%d",&l[i]);
	for(int i=1;i<=m;i++) scanf("%d",&r[i]);
	for(int i=1;i<=p;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}

}