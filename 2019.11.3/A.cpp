#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50050;
int n;
int w[MAXN];
int ans[MAXN];
int sum=0;
int cur;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) ans[i]=1;
	for(int i=n;i>=2;i--){
		if(w[i]>w[i-1]) ans[i]=ans[i-1]+1;
		if(w[i]<w[i-1]) ans[i]=1;
	}
	cur=ans[1];
	for(int i=2;i<=n;i++){
		if(w[i]>w[i-1]) ans[i]=ans[i-1]+1;
		if(w[i]<w[i-1]) ans[i]=1;
	}
	for(int i=1;i<=n;i++) sum+=ans[i];
	printf("%d\n",sum);
	return 0;
}
