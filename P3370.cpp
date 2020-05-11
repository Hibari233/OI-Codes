#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=10010;
const unsigned long long mod=212370440130137957;
int n,ans=1;
char s[N];
unsigned long long base=233,a[N];
unsigned long long hashe(char s[]){
	unsigned long long ans=0;
	for(int i=0;i<strlen(s);i++){
		ans=(ans*base+(unsigned long long)s[i])%mod;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		a[i]=hashe(s);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}