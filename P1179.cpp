#include<iostream>
using namespace std;
int l,r,ans=0;
int main(){
	scanf("%d%d",&l,&r);
	for(int i=l;i<=r;i++){
		int x=i;
		while(x!=0){
			if(x%10==2) ans++;
			x/=10;
		}
	}
	printf("%d\n",ans);
	return 0;
}