#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=110,M=N*N;
int n,m;
int f[N],u[N];
int h[N],e[M],w[M],ne[M],idx;
int din[N],dout[N];
int q[N];
void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void topsort(){
	int hh=0,tt=-1;
	for(int i=1;i<=n;i++)
		if(!din[i]){
			q[++tt]=i;
		}
	while(hh<=tt){
		int t=q[hh++];
		for(int i=h[t];~i;i=ne[i]){
			int j=e[i];
			if(--din[j]==0)
				q[++tt]=j;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&f[i],&u[i]);
	memset(h,-1,sizeof h);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		dout[a]++,din[b]++;
	}
	for(int i=1;i<=n;i++){
		if(din[i]){
			f[i]-=u[i];
		}
	}
	topsort();
	for(int i=0;i<n;i++){
		int j=q[i];
		if(f[j]>0)
			for(int k=h[j];~k;k=ne[k])
				f[e[k]]+=f[j]*w[k];
	}
	bool has_print=false;
	for(int i=1;i<=n;i++)
		if(!dout[i]&&f[i]>0){
			printf("%d %d\n",i,f[i]);
			has_print=true;
		}
	if(!has_print) puts("NULL");
	return 0;
}