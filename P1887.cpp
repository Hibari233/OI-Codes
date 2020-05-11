#include<iostream>
using namespace std;
int n,m;
int a[2000005];
int main(){
	scanf("%d%d",&n,&m);
	int tmp=n/m;
	int last=n%m;
	for(int i=m;i>=1;i--){
		if(last>0){
			a[i]=tmp+1;
			last--;
		}
		else{
			a[i]=tmp;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",a[i]);
	}
	return 0;
}