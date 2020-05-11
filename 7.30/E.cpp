#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string num;
int ans=0;
int calc(int i){
    if(num[i]=='+')
        return (num[i-1]-'0')+(num[i+1]-'0');
    if(num[i]=='-')
        return (num[i-1]-'0')-(num[i+1]-'0');
    if(num[i]=='*')
        return (num[i-1]-'0')*(num[i+1]-'0');
    if(num[i]=='/')
        return (num[i-1]-'0')/(num[i+1]-'0');
}
int main(){
    while(cin>>num){
        ans=0;
        if(num[0]=='0') return 0;
        for(int i=1;i<num.length()-1;i++){
            ans+=calc(i);
        }
        cout<<ans<<endl;
    }
    return 0;
}