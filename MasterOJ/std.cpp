#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bits\stdc++.h>
using namespace std;
const int N=10000050;
int n,q;
int a[N];
int sum[N];
int l[N],r[N];
int main(){
	freopen("ans.out","w",stdout);
	srand(time(NULL));
	q=rand();
	n=100;
	while(q>2000) q=rand();
	for(int i=1;i<=n;i++){
		a[i]=rand();
	}
	for(int i=1;i<=q;i++){
		l[i]=rand();
		r[i]=rand()*1000;
		while(l[i]>10000000) l[i]=rand();
		while(r[i]>10000000||r[i]>n) r[i]=rand()*1000;
		if(l[i]>=r[i]) swap(l[i],r[i]);
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	cout << n <<" "<< q << endl;
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	cout<<endl;
	for(int i=1;i<=q;i++) printf("%d %d\n",l[i],r[i]);
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	for(int i=1;i<=q;i++){
		printf("%d\n",sum[r[i]]-sum[l[i]-1]);
	}
	return 0;
}