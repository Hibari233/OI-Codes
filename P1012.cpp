#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=25;
int n;
string num[MAXN];
bool cmp(const string &a,const string &b){
	return a+b>b+a;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>num[i];
	sort(num+1,num+1+n,cmp);
	for(int i=1;i<=n;i++) cout<<num[i];
	printf("\n");
	return 0;
}