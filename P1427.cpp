#include<iostream>
using namespace std;
int a[1000];
int main(){
	int i=0;
	int tmp;
	while(cin>>tmp){
		if(tmp==0) break;
		a[++i]=tmp;
	}
	for(int j=i;j>=1;j--) printf("%d ",a[j]);
	printf("\n");
	return 0;
}