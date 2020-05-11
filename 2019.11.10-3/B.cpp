#pragma GCC optimize ("O3")
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=400050;
int n,a[N];
bool mark[N];
int ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(mark[a[i]]==true) {a[i]++;i--;ans++;continue;}
		mark[a[i]]=true;
	}
	printf("%d\n",ans);
	return 0;
}