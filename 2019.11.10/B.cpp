#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int N=150;
int p1,p2,p3;
char a[N];
char c[N][N];
bool check(int x){
	
}
int main(){
	scanf("%d%d%d",&p1,&p2,&p3);
	cin>>a;
	int pos=1,cur=0;
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='-') {pos++;cur=0;continue;}
		c[pos][cur]+=a[i];
	}
	if(p3==1){
		if(p1==1){
			for(int i=1;i<=pos-1;i++){
				cout<<c[i];
				for(char i=c[i][strlen(c[i])-1];i<=c[i+1][0];i++){
					
				}
			}
		}
	}
}