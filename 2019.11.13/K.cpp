#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstring>
using namespace std;
const long long N=1000050;
long long n,a[N],t[N],ans;
void merge(long long l,long long mid,long long r){
	long long i=l,j=mid,cnt=0;
	while(i<mid&&j<r){
		if(a[i]<=a[j]) t[cnt++]=a[i++];
		else t[cnt++]=a[j++],ans+=mid-i;
	}
	while(i<mid) t[cnt++]=a[i++];
	while(j<r) t[cnt++]=a[j++];
	for(long long i=0;i<cnt;i++) a[l+i]=t[i];
}
void merge_sort(long long l,long long r){
	if(r-l<=1) return;
	long long mid=(l+r)>>1;
	merge_sort(l,mid);
	merge_sort(mid,r);
	merge(l,mid,r);
}
int main(){
	scanf("%lld",&n);
	for(long long i=0;i<n;i++) scanf("%d",&a[i]);
	merge_sort(0,n);
	printf("%lld\n",ans);
	return 0;
}