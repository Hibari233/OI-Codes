#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=20;
int num[MAXN];
int main(){
	int n,total=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		num[i]=n-i+1,total*=i;
	}
	for(int i=1;i<=total;i++){
		next_permutation(num+1,num+n+1);
		for(int j=1;j<=n;j++){
			printf("    %d",num[j]);
		}
		printf("\n");
	}
	return 0;
}