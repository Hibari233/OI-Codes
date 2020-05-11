#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=1050;
const double eps=1e-7;
int n,t;
int s[MAXN],v[MAXN];
double ans;
bool check(double x){
	double sum=0;
	for(int i=1;i<=n;i++){
		double real=v[i]+x;
		sum+=(double)s[i]/real;
	}
	if(sum>=t+eps) return true;
	else return false;
}
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++) scanf("%d%d",&s[i],&v[i]);
	
	double l=-1050,r=1e7;
	for(int i=1;i<=n;i++){
		if(v[i]<0) l=max(l,(double)abs(v[i]));
	}
	while(r-l > eps){
		double mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid;
		}
		else r=mid;
	}
	printf("%.4lf\n",ans+eps);
	return 0;
}
/*
d = realspeed - feel
feel + d = realspeed
sigma(s[i]/real[i])=t

*/