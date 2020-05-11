#include<iostream>
using namespace std;
const int N=30;
int n;
int num[N]={6,2,5,5,4,5,6,3,7,6};
int get(int x){
	int ans=0;
	if(x==0) return 6;
	while(x!=0){
		int tmp=x%10;
		x/=10;
		ans+=num[tmp];
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	int res=0;
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++){
			int x=get(i),y=get(j);
			int z=get(i+j);
			if(x+y+z+4==n) res++;
		}
	}
	printf("%d\n",res);
}