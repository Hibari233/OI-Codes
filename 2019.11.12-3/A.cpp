#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
const int N=20050;
int n,a[N],ans=0,cur;
int main(){
	scanf("%d",&n);
	cur=n;
	for(int i=1;i<=n;i++) {scanf("%d",&a[i]);ans+=a[i];}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(cur==3) break;
		if(ans-a[i]>ans) {ans-=a[i];cur--;}
		else break;
	}
	printf("%d\n",ans);
	return 0;
}