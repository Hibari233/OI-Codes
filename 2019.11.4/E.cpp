#include<cstdio>
using namespace std;
const int MAXN=1000050;
int n,h[MAXN];
bool stat;
int ans=1;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	if(h[2]>=h[1]) stat=true;
	for(int i=1;i<=n;i++){
		if(stat==false&&i==n) ans++;
		else if(stat==true&&h[i+1]<h[i]) ans++,stat=false;
		else if(stat==false&&h[i+1]>h[i]) ans++,stat=true;
	}
	printf("%d\n",ans);
	return 0;
}