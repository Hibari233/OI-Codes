#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e6+10;
int n,m,l,r;
int Max[N][N];
int query(int l,int r){
	int k=log2(r-l+1);
	return max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&Max[i][0]);
	for(int j=1;j<=21;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
}