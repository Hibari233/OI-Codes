#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=300050;
long long n,a[MAXN];
long long total,sati;
double ans=-1;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		sati+=a[i];
		total++;
		double tmp=(1.0*sati*sati)/(1.0*total);
		if(tmp>ans){
			ans=tmp;
		}
	}
	printf("%.8f\n",ans);
	return 0;
}