#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int MAXN=10010;
int n;
unsigned long long a[MAXN];
char s[MAXN];
int base=233;
int ans=1;
unsigned long long mod=2123704401301379571;
unsigned long long hashe(char s[]){
    int len=strlen(s);
    unsigned long long ans=0;
    for(int i=0;i<len;i++){
        ans=(ans*base+(unsigned long long)s[i])%mod;
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        a[i]=hashe(s);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        if(a[i]!=a[i+1])
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}