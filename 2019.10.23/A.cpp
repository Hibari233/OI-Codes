#include<iostream>
using namespace std;
const int MAXN=100050;
int n;
int num[MAXN];
int count=0;
int mark[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {scanf("%d",&num[i]);if(num[i]>=0) count++;}
	for(int i=1;i<=n;i++){
		if(num[i]>=0) num[i]=-num[i]-1;
	}
	if(n%2==0){
		for(int i=1;i<=n;i++){
			printf("%d ",num[i]);
		}
	}
	else{
		int ans=0x7fffffff;
		int ii=1;
		for(int i=1;i<=n;i++){
			if(num[i]<ans) ans=num[i],ii=i;
		}
		num[ii]=-num[ii]-1;
		for(int i=1;i<=n;i++){
			cout<<num[i]<<" ";
		}
	}
	return 0;
}