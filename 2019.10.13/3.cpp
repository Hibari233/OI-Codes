#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int MAXN=105;
int n,k;
struct str{
	int p,k,o; 
}veg[MAXN];
bool operator < (const str &x,const str &y){
	return x.p>y.p;
}
bool is_prime(int n){
    if(n==1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}
bool check(int x){
	int total=0;
	for(int i=1;veg[i].p<=x;i++){
		for(int j=i+1;veg[j].p<=x;j++){
			if(is_prime(veg[i].k+veg[j].k)==true) return false;
		}
		total+=veg[i].o;
	}
	if(total>=k){
		return true;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&veg[i].o,&veg[i].k,&veg[i].p);
	}
	sort(veg+1,veg+1+n);
	int l=1,r=n,ans=0;
	while(l<r){
		int mid=(l+r)/2;
		printf("%d\n",mid);
		if(check(mid)==true) r=mid-1;
		if(check(mid)==false) l=mid+1;
		ans=mid;
	}
	printf("%d\n",ans);
	return 0;
}