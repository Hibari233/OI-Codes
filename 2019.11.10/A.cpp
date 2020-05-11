#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=200050;
int n,a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int num=a[i],cnt=0;
		for(int j=i;j<=n+2;j++){
			if(a[i]==a[j]) cnt++;
			else {i=i+cnt-1;break;}
		}
		printf("%d %d\n",num,cnt);
	}
	return 0;
}