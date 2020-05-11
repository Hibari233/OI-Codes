#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=3005;
int n,m,q;
int x[MAXN],y[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	printf("%d\n",n);
	return 0;
}