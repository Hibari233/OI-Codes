#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int m,n;
string a;
int main(){
	scanf("%d",&m);
	cin>>a;
	int pos=0;
	bool f=false;
	for(int i=a.length()-1;i>=0;i--){
		
		if(a[pos]!='0') {if(f==true) printf("+"); printf("%c*",a[pos++]); f=true;}
		else{ pos++;continue;}
		printf("%d^%d",m,i);
	}
	printf("\n");
	return 0;
}