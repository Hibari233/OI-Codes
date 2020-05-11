#pragma GCC optimize ("O3")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const long long N=2*100050;
long long n,g,r,q;
long long s[N];
template<typename node>void read(node &a){
    node x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=0;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=((x<<1)+(x<<3)+ch-'0');
        ch=getchar();
    }
    a=f?x:-x;
}
bool is_green(long long x){
	long long ans=x%(g+r);
	if(ans<g) return true;
	else return false;
}
long long calc(long long start,long long cur){
	cur=start;
	for(long long i=1;i<=n+1;i++){
		cur+=s[i];
		if(i==n+1) break;
		if(is_green(cur)==true) continue;
		else{
			cur+=(cur%(g+r))-g+1;
		}
	}
	return cur;
}
int main(){
	read(n);read(g);read(r);
	for(long long i=1;i<=n+1;i++) read(s[i]);
	read(q);
	for(long long i=1;i<=q;i++){
		long long t;
		read(t);
		long long ans=calc(t,0);
		printf("%lld\n",ans);
	}
	return 0;
}