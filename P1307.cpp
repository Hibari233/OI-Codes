#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
bool mark=false;
int main(){
	string n;
	cin>>n;
	if(n[0]=='-') printf("-");
	for(int i=n.length()-1;i>=0;i--){
		if(n[i]!='0') mark=true;
		if(n[i]=='0'&&mark==false) continue;
		if(n[i]=='-') continue;
		else cout<<n[i];
	}
	return 0;
}