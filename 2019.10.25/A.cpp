#include<iostream>
using namespace std;
long long a,b,y=1;
int main(){
	scanf("%lld%lld",&a,&b);
	while(true){
		long long ans=(b*y+1)/a;
		if(ans*a==(b*y)+1){
			printf("%lld\n",ans);
			return 0;
		}
		y++;
	}
}

/*
ax=1(mod b)
ax-by=1
ax=by+1

*/