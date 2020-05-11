#include<cstdio>
using namespace std;
const int MAXN=100050;
int n,a[MAXN];
int ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			ans+=a[i]-a[i-1];
		}
	}
	printf("%d\n",ans);
	return 0;
}