#include<iostream>
using namespace std;
const int MAXN=20500;
int n,ans=0;
int b[MAXN];
int mark[MAXN]={false};
int num[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		mark[num[i]]=true;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int total=num[i]+num[j];
			b[total]++;
		}
	}
	for(int i=1;i<=20005;i++){
		if(mark[i]==true&&b[i]>0) ans++;
	}
	printf("%d\n",ans);
	return 0;
}