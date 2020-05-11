#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
string a;
int count[30],maxx=-1,minn=0x3f3f3f3f;
bool Is_prime(int n){
	if(n==0) return false;
    if(n==1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}
int main(){
	cin>>a;
	for(int i=0;i<a.length();i++){
		count[a[i]-'a']++;
	}
	for(int i=0;i<=25;i++){
		if(count[i]==0) continue;
		maxx=max(maxx,count[i]);
		minn=min(minn,count[i]);
	}
	int ans=maxx-minn;
	if(Is_prime(ans)==true) printf("Lucky Word\n%d\n",ans);
	else printf("No Answer\n0\n");
	return 0;
}
// error a[0] = e a[1] = r a[2] = r a[2] = r 
// INT e-a 