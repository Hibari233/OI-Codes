#include<iostream>
using namespace std;
const int MAXN=100050;
int n,k;
int f[MAXN];
int main(){
	scanf("%d%d",&n,&k);
	f[0]=1,f[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=min(i,k);j>=1;j--){
			f[i]+=f[i-j];
			f[i]%=100003;
		}
	}
	printf("%d\n",f[n]);
	return 0;
}