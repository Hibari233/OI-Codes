#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int MAXN=10010;
int n;
unsigned long long a1;
unsigned long long a2;
char s[MAXN];
char s2[MAXN];
int base=233;
int ans=1;
unsigned long long mod=2123704401301379571;
unsigned long long hashe(char* s){
    int len=strlen(s);
    unsigned long long ans=0;
    for(int i=0;i<len;i++){
        ans=(ans*base+(unsigned long long)s[i])%mod;
    }
    return ans;
}
int main(){
	cin>>s;
	cin>>s2;
	int len=strlen(s2);
	for(int i=0;s[i];i++){

	}
    return 0;
}